#pragma once

#ifndef PROMPT_HPP
#define PROMPT_HPP

#include <string>

#include "Contact.hpp"

std::string prompt_string(const std::string &prompt);
bool prompt_contact(Contact &contact);
int prompt_contact_index(int contact_count);

#endif
