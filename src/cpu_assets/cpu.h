#pragma once

#include <string>

namespace vm
{
    class RAM;

    /**
     * @brief This class is an interface for all CPU type objects.
     * 
     * @details If your are going to provide a specific type of MCU or CPU, you must derive from this class
     * and provide proper implementation for all the functions. The 8bit VM will requires the interface
     * to interact with all types of processors. If there's any issue or missing function, please
     * report [here](https://github.com/arsdever/vm)
     * 
     * @see RAM
     * @author [arsdever](https://github.com/arsdever)
     */
    class CPU
    {
    public:
        /**
         * @brief Start the CPU execution.
         * 
         * @details This action is like powering on the CPU. If you have already started the CPU,
         * another call to start the CPU must do nothing. To check whether the CPU is started you can use
         * @ref isRunning() function.
         * 
         * @param debug start processor in debug mode.
         * @return true if processor is started.
         * @return false if processor is not started or already has been started.
         * 
         * @see isRunning() const
         */
        virtual bool start(bool debug = false) = 0;

        /**
         * @brief Reset the CPU.
         * 
         * @details This action is like resetting the CPU. It will reset the state of CPU into state it was on
         * startup. After resetting the CPU must be in running state.
         */
        virtual void reset() = 0;
        
        /**
         * @brief Stop the CPU execution.
         * 
         * @details This action is like powering off the CPU. But instead, it will not lose its state.
         */
        virtual void stop() = 0;

        /**
         * @brief Check whether the CPU is in running state
         * 
         * @return true 
         * @return false 
         */
        virtual bool isRunning() const = 0;
        virtual int tick() = 0;
        virtual RAM* ram() const = 0;
        virtual std::string disassemble() const = 0;

#ifdef DEBUGGING
        virtual std::string dump() const = 0;
#endif

    protected:
        virtual void fetch() = 0;
        virtual void decode() = 0;
        virtual void execute() = 0;
    };
}