/* 
 * File:   SlotIO.h
 * Author: nathanael
 *
 * Created on April 23, 2012, 1:15 PM
 */

#ifndef SLOTIO_H
#define	SLOTIO_H

#include "Defines.h"

/*! \brief Response flags:
 * 
 */
#define PERMISSION_GRANTED 0b00000001
#define ERR_ID_INCORRECT 0b00000010
#define ERR_UNAUTHORISED 0b00000100
#define ERR_BLOCKED 0b00001000
#define ERR_SERVER_CHECKSUM 0b00010000
#define TEST_FRAME_ANSWER 0b00100000

class SlotIO {
public:
    /*! \brief Constructor for SlotIO*/
    SlotIO();
    /*! \brief Netbeans generated second constructor.*/
    SlotIO(const SlotIO& orig);
    /*! \brief SlotIO deconstructor.*/
    virtual ~SlotIO();
    
    /*! \brief Processes the input given by users.
     * \return next_state Returns the next state to be executed by the state machine.
     */
    bool detectEntry();
    
    /*! \brief Turns the response packets into orders.
     * \param * response A pointer to the response packet generated by the Communication class.
     * \return next_state Returns the next state to be executed by the state machine.
     */
    int setOutput(uint8_t flags);
    
    /*! \brief Sets the door state.
     * \param state the state to set the door to. Either OPEN or CLOSED.
     */
    void SetDoorState(bool state);
    
    /*! \brief Returns the state of the door.
     * \return Returns the state of the door. Either OPEN or CLOSED.
     */
    bool GetDoorState();
    
    /*! \brief Getter for the student ID.
     * Allows another class to get the ID input by the user.
     * \return returns the student ID in a 32 bit unsigned int.
     */
    uint32_t getStudentID();
    
    /*! \brief Getter for the pin
     * Allows another class to get the pin input by the user.
     * \return returns the pin in a 16 bit unsigned int.
     */
    uint16_t getPin();
    
    
/*! \brief A macro to flush the input from the command line.
 * Macro om stdin te flushen.
 http://www.daniweb.com/software-development/c/code/217396
 */
char Junk[16]; // buffer for discarding excessive user input, used by "FLUSH_STDIN" macro
#define FLUSH_STDIN(x) {if(x[strlen(x)-1]!='\n'){do fgets(Junk,16,stdin);while(Junk[strlen(Junk)-1]!='\n');}else x[strlen(x)-1]='\0';}
    
private:
    uint32_t studentID;
    uint16_t pin;
    bool door_state;
};

#endif	/* SLOTIO_H */

