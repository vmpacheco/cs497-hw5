#include <plx/data/Array.hpp>
#include <plx/data/Closure.hpp>
#include <plx/data/List.hpp>
#include <plx/data/Triple.hpp>
#include <plx/evaluator/Evaluator.hpp>
#include <plx/expr/Function.hpp>
#include <plx/literal/Nil.hpp>
#include <plx/literal/String.hpp>
#include <plx/object/Globals.hpp>
#include <plx/object/ThrowException.hpp>
#include <plx/object/TypeIds.hpp>

namespace PLX {

    Function::Function(List* parameters, Object* body)
        : _params {parameters}
        , _body {body}
    {}

    Object* Function::eval(Evaluator* etor) {
        Closure* closure = new Closure(this, etor->environment());
        return closure;
    }

    void Function::showOn(std::ostream& ostream) const {
        List* params = _params;
        ostream << "fun (";

        while(!params->isEmpty()) {
            ostream << params->first();
            params = params->restAsList();
        }

        ostream << ") = "
                << _body;
    }

    List* Function::getParams() {
        return _params;
    }

    Object* Function::getBody() {
        return _body;
    }

    TypeId Function::typeId() const {
        return TypeId::E_FUNCTION;
    }

}