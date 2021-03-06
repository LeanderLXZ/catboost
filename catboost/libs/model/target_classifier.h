#pragma once

#include <util/generic/vector.h>
#include <util/ysaveload.h>

class TTargetClassifier {
public:
    int GetTargetClass(double target) const {
        int resClass = 0;
        while (resClass < Borders.ysize() && target > Borders[resClass]) {
            ++resClass;
        }
        return resClass;
    }

    int GetClassesCount() const {
        return Borders.ysize() + 1;
    }

    TTargetClassifier() = default;

    explicit TTargetClassifier(const yvector<float>& borders)
        : Borders(borders)
    {
    }
    bool operator==(const TTargetClassifier& other) const {
        return Borders == other.Borders;
    }
    Y_SAVELOAD_DEFINE(Borders);

private:
    yvector<float> Borders;
};
