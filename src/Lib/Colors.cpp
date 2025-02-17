#include "../../headers/Lib/Colors.h"

// Basic Colors
string Colors::GetBlack() {
    return "\033[0;30m";
}
string Colors::GetRed() {
    return "\033[0;31m";
}
string Colors::GetGreen() {
    return "\033[0;32m";
}
string Colors::GetYellow() {
    return "\033[0;33m";
}
string Colors::GetBlue() {
    return "\033[0;34m";
}
string Colors::GetMagenta() {
    return "\033[0;35m";
}
string Colors::GetCyan() {
    return "\033[0;36m";
}
string Colors::GetWhite() {
    return "\033[0;37m";
}

// Bold Colors
string Colors::GetBoldBlack() {
    return "\033[1;30m";
}
string Colors::GetBoldRed() {
    return "\033[1;31m";
}
string Colors::GetBoldGreen() {
    return "\033[1;32m";
}
string Colors::GetBoldYellow() {
    return "\033[1;33m";
}
string Colors::GetBoldBlue() {
    return "\033[1;34m";
}
string Colors::GetBoldMagenta() {
    return "\033[1;35m";
}
string Colors::GetBoldCyan() {
    return "\033[1;36m";
}
string Colors::GetBoldWhite() {
    return "\033[1;37m";
}

// Reset Color
string Colors::RESET() {
    return "\033[0m";
}

// Func to get Color
string Colors::GetColor(enColors color) {
    switch (color) {
        case Colors::Black: {
            return GetBlack();
            break;
        }
        case Colors::Red: {
            return GetRed();
            break;
        }
        case Colors::Yellow: {
            return GetYellow();
            break;
        }
        case Colors::Green: {
            return GetGreen();
            break;
        }
        case Colors::Blue: {
            return GetBlue();
            break;
        }
        case Colors::Magenta: {
            return GetMagenta();
            break;
        }
        case Colors::Cyan: {
            return GetCyan();
            break;
        }
        case Colors::White: {
            return GetWhite();
            break;
        }
        case Colors::BoldRed: {
            return GetBoldRed();
            break;
        }
        case Colors::BoldGreen: {
            return GetBoldGreen();
            break;
        }
        case Colors::BoldYellow: {
            return GetBoldYellow();
            break;
        }
        case Colors::BoldBlue: {
            return GetBoldBlue();
            break;
        }
        case Colors::BoldMagenta: {
            return GetBoldMagenta();
            break;
        }
        case Colors::BoldCyan: {
            return GetBoldCyan();
            break;
        }
        case Colors::BoldWhite: {
            return GetBoldWhite();
            break;
        }
        case Colors::Reset: {
            return RESET();
            break;
        }
        default: {
            return GetWhite();
            break;
        }
    }
}
