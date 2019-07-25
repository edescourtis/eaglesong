#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "eaglesong.h"
#include "erl_nif.h"

#define EAGLESONG_DIGEST_SIZE_BYTES 32

ERL_NIF_TERM mk_atom(ErlNifEnv* env, const char* atom);
ERL_NIF_TERM mk_error(ErlNifEnv* env, const char* mesg);
static ERL_NIF_TERM hash(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]);

ERL_NIF_TERM mk_atom(ErlNifEnv* env, const char* atom)
{
    ERL_NIF_TERM ret;

    if(!enif_make_existing_atom(env, atom, &ret, ERL_NIF_LATIN1))
    {
        return enif_make_atom(env, atom);
    }

    return ret;
}

ERL_NIF_TERM mk_error(ErlNifEnv* env, const char* mesg)
{
    return enif_make_tuple2(env, mk_atom(env, "error"), mk_atom(env, mesg));
}

static ERL_NIF_TERM hash(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[]) 
{
	ErlNifBinary in_bin;
	ErlNifBinary out_bin;
	ERL_NIF_TERM final_bin;
	int res;

	if(argc != 1) return enif_make_badarg(env);

	res = enif_inspect_binary(env, argv[0], &in_bin);
	if(res == 0) return enif_make_badarg(env);

	if(enif_alloc_binary(EAGLESONG_DIGEST_SIZE_BYTES, &out_bin) == 0){
		return mk_error(env, "binary_alloc_failed");
	}

	EaglesongHash(out_bin.data, in_bin.data, in_bin.size);
	final_bin = enif_make_binary(env, &out_bin);
	enif_release_binary(&out_bin);
	return final_bin;
}

static ErlNifFunc nif_funcs[] = {
	{"hash", 1, hash}
};

ERL_NIF_INIT(eaglesong, nif_funcs, NULL, NULL, NULL, NULL);

