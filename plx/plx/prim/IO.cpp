#include <cassert>

#include <plx/data/Array.hpp>
#include <plx/data/List.hpp>
#include <plx/data/Queue.hpp>
#include <plx/evaluator/Evaluator.hpp>
#include <plx/literal/Integer.hpp>
#include <plx/literal/Nil.hpp>
#include <plx/literal/String.hpp>
#include <plx/object/Globals.hpp>
#include <plx/object/Object.hpp>
#include <plx/object/ThrowException.hpp>
#include <plx/object/TypeIds.hpp>
#include <plx/prim/Primitive.hpp>

namespace PLX {
    namespace Prim_IO {

        Object* display(Evaluator* etor, List* args) {
            List* argEval = evalArgs(etor, args);
            std::ostream& ostream = std::cout;
            while(!argEval->isEmpty()){
                Object* arg = argEval->first();
                arg->displayOn(ostream);
                argEval = argEval->restAsList();
            }
            return GLOBALS->NilObject();
        }

        Object* nl(Evaluator* etor, List* args) {
            const std::string PRIM_NAME = "nl";
            evalNArgs(PRIM_NAME, etor, args, {});
            std::cout << '\n';
            return GLOBALS->NilObject();
        }

        Object* readLine(Evaluator* etor, List* args) {
            const std::string PRIM_NAME = "readLine";
            evalNArgs(PRIM_NAME, etor, args, {});
            std::string input;
            std::getline(std::cin, input);
            return new String(input);
        }

        Object* show(Evaluator* etor, List* args) {
            List* argEval = evalArgs(etor, args);
            std::ostream& ostream = std::cout;
            while(!argEval->isEmpty()){
                Object* arg = argEval->first();
                arg->showOn(ostream);
                argEval = argEval->restAsList();
            }
            return GLOBALS->NilObject();
        }

    }
}
