#pragma once

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <ostream>
#include <string>

class Contact {
public:
  const std::string &get_first_name() const;
  const std::string &get_last_name() const;
  const std::string &get_nickname() const;
  const std::string &get_phone_number() const;
  const std::string &get_darkest_secret() const;

  bool is_empty() const;

  void set_data(std::string first_name, std::string last_name,
                std::string nickname, std::string phone_number,
                std::string darkest_secret);

  void print() const;

private:
  std::string first_name;
  std::string last_name;
  std::string nickname;
  std::string phone_number;
  std::string darkest_secret;
};

#endif
