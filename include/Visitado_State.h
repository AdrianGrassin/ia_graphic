//
// Created by Adri on 10/11/2022.
//

#ifndef P2___GRAPHICS_INCLUDE_VISITADO_STATE_H_
#define P2___GRAPHICS_INCLUDE_VISITADO_STATE_H_
#include "estado.h"

class Visitado_State : public Estado {
 private:
    char visitado_;

    public:
    Visitado_State() : visitado_('.') {}
    char get_symbol() override;


};

#endif //P2___GRAPHICS_INCLUDE_VISITADO_STATE_H_
