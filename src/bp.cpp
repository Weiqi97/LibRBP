#include "bp.hpp"

BP::BP(const bool& pre){
    // Initialize the core and set curve parameter.
    init();

    // Get the order of the curve.
    Fp order;
    pc_get_ord(order.value);

    // Set the order to the zp field.
    Zp = std::make_unique<Field>(order);

    // Use precomputed table if set.
    Gp = std::make_unique<Group>(pre);
}

void BP::init(){
    core_init();
    pc_param_set_any();
}

void BP::close(){
    core_clean();
}
