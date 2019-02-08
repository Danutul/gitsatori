#pragma once
#include "VirtualState.h"
#include <memory>
#include <stack>
namespace Dan
{
	typedef std::unique_ptr<VirtualState> uPointerState;

	class StateManager
	{
	public:
		StateManager() {}
		~StateManager() {}
		void AddState(uPointerState newState, bool isReplacing = true);
		void RemoveState();
		void ManageStates();

		uPointerState& GetState();

	private:
		std::stack<uPointerState> _states;
		uPointerState _newState;
		

		bool _isReplacing;
		bool _isAdding;
		bool _isRemoving;
	};
}