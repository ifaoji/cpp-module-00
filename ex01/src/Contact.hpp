#pragma once

#include <ostream>
#ifndef __CONTACT_HPP__
#define __CONTACT_HPP__

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

  friend std::ostream &operator<<(std::ostream &os, const Contact &contact);

private:
  std::string first_name;
  std::string last_name;
  std::string nickname;
  // TODO: which datatype should this be
  std::string phone_number;
  std::string darkest_secret;
};

#endif
