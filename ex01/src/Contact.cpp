#include "Contact.hpp"

void Contact::set_data(std::string first_name, std::string last_name,
                       std::string nickname, std::string phone_number,
                       std::string darkest_secret) {
  this->first_name = first_name;
  this->last_name = last_name;
  this->nickname = nickname;
  this->phone_number = phone_number;
  this->darkest_secret = darkest_secret;
}

const std::string &Contact::get_first_name() const { return this->first_name; }

const std::string &Contact::get_last_name() const { return this->last_name; }

const std::string &Contact::get_nickname() const { return this->nickname; }

const std::string &Contact::get_phone_number() const {
  return this->phone_number;
}

const std::string &Contact::get_darkest_secret() const {
  return this->darkest_secret;
}

bool Contact::is_empty() const {
  return this->darkest_secret.empty() && this->first_name.empty() &&
         this->last_name.empty() && this->nickname.empty() &&
         this->phone_number.empty();
}

std::ostream &operator<<(std::ostream &os, const Contact &c) {
  os << "First Name: " << c.first_name << std::endl;
  os << "Last Name: " << c.last_name << std::endl;
  os << "Nickname: " << c.nickname << std::endl;
  os << "Phone Number: " << c.phone_number << std::endl;
  os << "Darkest Secret: " << c.darkest_secret << std::endl;

  return os;
}
