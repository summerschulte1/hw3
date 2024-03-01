#include <vector>
#include <random>
#include <iostream>

#include "gate.h"
#include "wire.h"

Gate::Gate(int num_inputs, Wire* output) 
	: m_output(output), m_inputs(num_inputs), m_delay(0), m_current_state('X')
{
    
}

Gate::~Gate(){}

void Gate::wireInput(unsigned int id, Wire* in)
{
    if(id < m_inputs.size())
    {
        m_inputs[id] = in;
    }
}

And2Gate::And2Gate(Wire* a, Wire* b, Wire* o) : Gate(2,o)
{
    wireInput(0,a);
    wireInput(1,b);
}

Event* And2Gate::update(uint64_t current_time)
{
    
  char state = '1';
  Event* e = nullptr;
	for(auto w : m_inputs)
	{
		char in = w->getState();
		if(in == '0')
		{
			state = '0';
			break;
		}
		else if(in == 'X')
		{
			state = 'X';
		}
	}
    if(state != m_current_state)
	{
    m_current_state = state;
    uint64_t next = current_time + m_delay;
		e = new Event {next,m_output,state};
         
	}
    return e;
}

Or2Gate::Or2Gate(Wire* a, Wire* b, Wire* o) : Gate(2,o)
{
    wireInput(0,a);
    wireInput(1,b);
}

Event* Or2Gate::update(uint64_t current_time)
{
    
  char state = '0';
  Event* e = nullptr;
	for(auto w : m_inputs)
	{
		char in = w->getState();
		if(in == '1')
		{
			state = '1';
			break;
		}
		else if(in == 'X')
		{
			state = 'X';
		}
	}
  if(state != m_current_state)
	{
    m_current_state = state;
		uint64_t next = current_time + m_delay;
		e = new Event {next,m_output,state};
         
	}
  return e;
}
NotGate::NotGate(Wire* input, Wire* output) : Gate(1, output)
{
    wireInput(0, input); // Connect the input wire
}

Event* NotGate::update(uint64_t current_time)
{
    char state = m_inputs[0]->getState(); // Get the current state of the input wire
    char newState = 'X'; // Default to 'X'

    // Apply the NOT operation based on the input state
    switch (state) {
        case '0':
            newState = '1';
            break;
        case '1':
            newState = '0';
            break;
        case 'X':
            newState = 'X';
            break;
    }

    // Create an event if the state has changed
    Event* e = nullptr;
    if(newState != m_current_state) {
        m_current_state = newState;
        uint64_t nextTime = current_time + m_delay;
        e = new Event{nextTime, m_output, newState};
    }

    return e;
}

