#include "Program.h";

Program::Program(){
    this->setState(new DefaultState());
}
void Program::update(){
    this->state.update();
}
void Program::setState(IState *state){
    this->state = *state;
}
IState Program::getState(){
    return this->state;
}