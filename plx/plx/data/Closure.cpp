#include <cassert>

#include <plx/data/Array.hpp>
#include <plx/data/Closure.hpp>
#include <plx/data/List.hpp>
#include <plx/data/Queue.hpp>
#include <plx/data/Triple.hpp>
#include <plx/evaluator/Evaluator.hpp>
#include <plx/expr/Function.hpp>
#include <plx/literal/Nil.hpp>
#include <plx/literal/String.hpp>
#include <plx/object/Globals.hpp>
#include <plx/object/TypeIds.hpp>

namespace PLX {

    Closure::Closure(Function* fun, Triple* environment)
        : _function{fun}
        , _lexicalEnvironment{environment}
    {}

    Object* Closure::apply(Evaluator* etor, List* arguments) {
        Triple* savedEnv = etor->environment();
        etor->setEnvironment(_lexicalEnvironment);
        List* args = arguments;
        List* params = _function->getParams();
        Object* val = GLOBALS->NilObject();
        
        while (!args->isEmpty()) {
            etor->bind(params->first(), args->first());
            args = args->restAsList();
            params = params->restAsList();
        }

        val = etor->evalExpr(_function->getBody());
        etor->setEnvironment(savedEnv);
        return val;
    }

    void Closure::showOn(std::ostream& ostream) const {
        ostream << _function;
    }

    TypeId Closure::typeId() const {
        return TypeId::D_CLOSURE;
    }

}