-module(eaglesong).

%% API exports
-export([hash/1]).
-on_load(init/0).

-define(APPNAME, eaglesong).
-define(LIBNAME, eaglesong).

%%====================================================================
%% API functions
%%====================================================================
hash(_) ->
    not_loaded(?LINE).

init() ->
    SoName = case code:priv_dir(?APPNAME) of
        {error, bad_name} ->
            case filelib:is_dir(filename:join(["..", priv])) of
                true ->
                    filename:join(["..", priv, ?LIBNAME]);
                _ ->
                    filename:join([priv, ?LIBNAME])
            end;
        Dir ->
            filename:join(Dir, ?LIBNAME)
    end,
    erlang:load_nif(SoName, 0).



%%====================================================================
%% Internal functions
%%====================================================================
not_loaded(Line) ->
    exit({not_loaded, [{module, ?MODULE}, {line, Line}]}).
