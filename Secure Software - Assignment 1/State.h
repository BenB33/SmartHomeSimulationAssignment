#pragma once
#include <unordered_map>
#include <string>

enum class state { off, on };

const static std::unordered_map<state, std::string> stateString
{
	std::make_pair(state::off, "Off"),
	std::make_pair(state::on, "On"),
};