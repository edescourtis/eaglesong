eaglesong
=====

Eaglesong is the PoW (proof of work) hash used in Nervos CKB. This library is a simple nif to use it from Erlang and other BEAM languages such as Elixir.

Adding as a dependency
-----

In Elixir (`mix.exs`):
```
{:eaglesong, "~> 1.0"}
```

In Erlang (`rebar.config`):
```
{eaglesong, "1.0.0"}
```


Build
-----
    $ rebar3 compile

Example usage from REPL
-----
```bash
$ rebar3 shell
===> Verifying dependencies...
===> Compiling eaglesong
make: Entering directory 'eaglesong/c_src'
cc -O3 -std=c99 -finline-functions -Wall -Wmissing-prototypes -fPIC -I erlang/21.3.8.4/erts-10.3.5.3/include/ -I erlang/21.3.8.4/lib/erl_interface-3.11.3/include  -c -o eaglesong/c_src/eaglesong_nif.o eaglesong/c_src/eaglesong_nif.c
cc -O3 -std=c99 -finline-functions -Wall -Wmissing-prototypes -fPIC -I erlang/21.3.8.4/erts-10.3.5.3/include/ -I erlang/21.3.8.4/lib/erl_interface-3.11.3/include  -c -o eaglesong/c_src/eaglesong.o eaglesong/c_src/eaglesong.c
cc eaglesong/c_src/eaglesong_nif.o eaglesong/c_src/eaglesong.o -shared -L erlang/21.3.8.4/lib/erl_interface-3.11.3/lib -lerl_interface -lei -o eaglesong/c_src/../priv/eaglesong.so
make: Leaving directory 'eaglesong/c_src'
Erlang/OTP 21 [erts-10.3.5.3] [source] [64-bit] [smp:36:36] [ds:36:36:10] [async-threads:0] [hipe]

Eshell V10.3.5.3  (abort with ^G)
1> l(eaglesong).
{module,eaglesong}
2> eaglesong:hash(<<"Hello World\n">>).
<<190,235,188,189,183,3,171,48,65,215,88,14,190,17,102,
  101,93,240,130,243,239,168,7,65,43,19,28,202,105,...>>
3> 
```

License
----

MIT
