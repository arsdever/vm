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
         * @brief Check whether the CPU is in running state.
         * 
         * @return true if CPU is in running state
         * @return false if CPU is stopped
         */
        virtual bool isRunning() const = 0;
        
        /**
         * @brief Generate a single clock tick.
         * 
         * @details After starting the CPU this function is used to generate external clock ticks.
         * The meaning of the return value of the function is described by the implementer. It could be
         *  - ticks until the current instruction will be completed
         *  - ticks already produced
         *  - or something else.
         * 
         * For actual purpose please have a look at the implementers documentation.
         * 
         * @return int user defined
         */
        virtual int tick() = 0;

        /**
         * @brief The RAM instance used by the CPU.
         * 
         * @return RAM* the ram instance
         */
        virtual RAM* ram() const = 0;
        
        /**
         * @brief Disassemble the current instruction.
         * 
         * @details Disassembles and returns the disassembled string of the instruction under current
         * program counter. This is a useful function when writing debugging tools.
         * 
         * @return std::string the disassembled instruction
         */
        virtual std::string disassemble() const = 0;

#ifdef DEBUGGING
        /**
         * @brief Dump the CPU state.
         * 
         * @return std::string the CPU state
         */
        virtual std::string dump() const = 0;
#endif

    protected:
        /**
         * @brief Fetch the next instruction.
         * 
         * @details Read the next instruction from RAM and place into instruction register (if exists) if necessary.
         * This is a first of the common steps in the execution of most kinds processors.
         * 
         * @see decode()
         * @see execute()
         */
        virtual void fetch() = 0;

        /**
         * @brief Decode the fetched instruction.
         * 
         * @details Increment the program counter depending on the instruction and determine the executor which
         * will execute the instruction.
         * 
         * @see fetch()
         * @see execute()
         */
        virtual void decode() = 0;

        /**
         * @brief Execute the fetched instruction.
         * 
         * @details Simply execute the executor, which already is decoded and knows how to execute the instruction.
         * 
         * @see fetch()
         * @see decode()
         */
        virtual void execute() = 0;
    };
}