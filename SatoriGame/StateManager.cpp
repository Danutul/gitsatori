#pragma once
#include "StateManager.h"
namespace Dan
{
	void StateManager::AddState(uPointerState newState, bool isReplacing)
	{
		this->_isAdding = true;
		this->_isReplacing = isReplacing;
		this->_newState = std::move(newState);
	}

	void StateManager::RemoveState()
	{
		this->_isRemoving = true;
	}

	void StateManager::ManageStates()
	{
		if (this->_isRemoving && !this->_states.empty())
		{
			this->_states.pop();
			if (!_states.empty())
			{
				_states.top()->Resume();
			}
			_isRemoving = false;
		}

		if (this->_isAdding)
		{
			if (!this->_states.empty())
			{
				if (this->_isReplacing)
				{
					this->_states.pop();
				}
				else
				{
					this->_states.top()->Pause();
				}
			}
			this->_states.push(std::move(this->_newState));
			this->_states.top()->Init();
			this->_isAdding = false;
		}
	}

	uPointerState & StateManager::GetState()
	{
		return this->_states.top();
	}
}