#pragma once

#ifndef __PHONE_BOOK_HPP__
#define __PHONE_BOOK_HPP__

#include <ostream>

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
public:
  PhoneBook();

  void add_contact(const Contact &contact);
  int contact_count() const;

  const Contact *get_contact(int index) const;
  void print() const;

private:
  Contact contacts[MAX_CONTACTS];
  int oldest_contact_idx;
};

#endif
