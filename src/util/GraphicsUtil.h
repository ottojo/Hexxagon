//
// Created by jonas on 30.12.19.
//

#ifndef HEXXAGON_GRAPHICSUTIL_H
#define HEXXAGON_GRAPHICSUTIL_H


namespace util {
    class GraphicsUtil {
    public:
        template<typename T>
        static void setOriginToCenter(T &object) {
            object.setOrigin(object.getLocalBounds().left + 0.5f * object.getLocalBounds().width,
                             object.getLocalBounds().top + 0.5f * object.getLocalBounds().height);
        }
    };
}

#endif //HEXXAGON_GRAPHICSUTIL_H
