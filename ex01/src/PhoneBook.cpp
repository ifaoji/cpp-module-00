#include <iomanip>
#include <iostream>

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contacts(), oldest_contact_idx(-1) {}

void PhoneBook::add_contact(const Contact &contact) {
  this->oldest_contact_idx = (this->oldest_contact_idx + 1) % MAX_CONTACTS;

  this->contacts[this->oldest_contact_idx] = contact;
}

int PhoneBook::contact_count() const {
  int i = 0;

  while (i < MAX_CONTACTS) {
    if (this->contacts[i].is_empty())
      break;

    i++;
  }

  return i;
}

const Contact *PhoneBook::get_contact(int index) const {
  if (index < 0 || index > this->contact_count() - 1)
    return NULL;

  return &this->contacts[index];
}

static inline std::string print_truncated(const std::string &str) {
  if (str.length() <= 10)
    return str;

  return str.substr(0, 9) + ".";
}

std::ostream &operator<<(std::ostream &os, const PhoneBook &pb) {
  os << "|" << std::setw(10) << "Index" << std::setw(0);
  os << "|" << std::setw(10) << "First Name" << std::setw(0);
  os << "|" << std::setw(10) << "Last Name" << std::setw(0);
  os << "|" << std::setw(10) << "Nickname" << std::setw(0) << "|";
  os << std::endl;

  for (int i = 0; i < MAX_CONTACTS; i++) {
    Contact contact = pb.contacts[i];
    if (contact.is_empty())
      continue;

    os << "|" << std::setw(10) << i << std::setw(0);
    os << "|" << std::setw(10) << print_truncated(contact.get_first_name())
       << std::setw(0);
    os << "|" << std::setw(10) << print_truncated(contact.get_last_name())
       << std::setw(0);
    os << "|" << std::setw(10) << print_truncated(contact.get_nickname())
       << std::setw(0) << "|";

    os << std::endl;
  }

  return os;
}
