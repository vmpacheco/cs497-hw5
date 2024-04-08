#include <cassert>

#include <plx/data/List.hpp>
#include <plx/evaluator/Evaluator.hpp>
#include <plx/expr/Apply.hpp>
#include <plx/object/TypeIds.hpp>
#include <plx/object/TypeIds.hpp>
#include <plx/object/Globals.hpp>
#include <plx/literal/Nil.hpp>

namespace PLX {

    Apply::Apply(Object* abstractionObj, List* args)
        : _abstractionObj {abstractionObj}
        , _arguments {args}
    {}

    Object* Apply::eval(Evaluator* etor) {
        Object* abstr = etor->evalExpr(_abstractionObj);
        return abstr->apply(etor, _arguments);

        /*
        etor->evalExpr(_abstractionObj);
        List* args = _arguments;

        while(!args->isEmpty()) {
            args->setFirst(etor->evalExpr(args->first()));
            args = args->restAsList();
        }

        _abstractionObj->apply(etor, args);
        */
    }

    void Apply::showOn(std::ostream& ostream) const {
        switch (_abstractionObj->typeId()) {
            case TypeId::D_CLOSURE:
            case TypeId::E_FUNCTION:
            case TypeId::E_NAMEDFUNCTION:
                ostream << '(' << _abstractionObj << ')';
                break;
            default:
                ostream << _abstractionObj;
                break;
        }
        _arguments->showOnWith(ostream, "(", ", ", ")");
    }

    TypeId Apply::typeId() const {
        return TypeId::E_APPLY;
    }

}
