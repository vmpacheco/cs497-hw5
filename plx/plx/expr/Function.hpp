#pragma once

#include <plx/object/Object.hpp>

namespace PLX {

    class List;

    class Function : public Object {
    public:
        Function(List* parameters, Object* body);
        List* getParams();
        Object* getBody();

        // Unique functions ------------------------------------------------

        // Overridden functions --------------------------------------------

        Object* eval(Evaluator* etor) override;
        void showOn(std::ostream& ostream) const override;
        TypeId typeId() const override;

    private:
        List* _params;
        Object* _body;
    };

}
