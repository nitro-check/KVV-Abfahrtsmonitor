#pragma once

//Could just use an enum without "class", but
//now access through e.g. State::INIT to avoid confusion.
enum class State {
    SETUP, //0
    COUNT, //NOT AN ACTUAL STATE. "static_cast<uint8_t>(State::COUNT);""
           //can be used to count the number of states.
};