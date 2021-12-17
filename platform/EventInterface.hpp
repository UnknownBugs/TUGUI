/*
 * @Author: tiansongyu
 * @Date: 2021-11-29 23:55:54 
 * @Last Modified by: tiansongyu
 * @Last Modified time: 2021-11-29 00:12:48
 */

#ifndef __EVENT_INTERFACE_HPP__
#define __EVENT_INTERFACE_HPP__


namespace TUGUI {

namespace INTERFACE {

class EventInterface {

public:

    using CallBack = void (*)();

    virtual void timerEvent(CallBack cb, unsigned int ms) {
        // Nothing
    }

}; // EventInterface

extern EventInterface *gEventInterfacePtr;

}; // INTERFACE
}; // TUGUI

#endif // __EVENT_INTERFACE_HPP__