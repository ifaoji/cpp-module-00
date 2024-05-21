#include <iostream>
#include <string>

#include "PhoneBook.hpp"
#include "prompt.hpp"

void start_game(PhoneBook &phone_book) {
  std::cout << "Welcome to crappy awesome phone book software!" << std::endl;
  std::cout << "Here are all available commands:" << std::endl;
  std::cout << "\tADD: Save a new contact" << std::endl;
  std::cout << "\tSEARCH: Display a specific contact" << std::endl;
  std::cout << "\tEXIT: Burn the phone book" << std::endl;
  std::cout << std::endl;

  while (true) {
    std::string command = prompt_string("Enter a command");

    if (std::cin.fail() || command == "EXIT") {
      break;
    }

    if (command == "SEARCH") {
      if (phone_book.contact_count() == 0) {
        std::cout << "Your phonebook is empty. Please add a contact before "
                     "trying to search."
                  << std::endl;

        continue;
      }

      phone_book.print();

      int index = prompt_contact_index(phone_book.contact_count());
      if (std::cin.fail())
        break;

      if (index < 0) {
        std::cout << "Error: You did not enter a valid index." << std::endl;

        continue;
      }

      const Contact *contact = phone_book.get_contact(index);
      if (contact == NULL) {
        std::cout << "Error: There is no contact for this index? How did you "
                     "bypass the input checking?"
                  << std::endl;

        continue;
      }

      contact->print();

      continue;
    }

    if (command == "ADD") {
      Contact contact;

      if (!prompt_contact(contact)) {
        if (std::cin.fail())
          break;
        std::cout << "Error: Failed to add new contact." << std::endl;

        continue;
      }

      phone_book.add_contact(contact);

      continue;
    }

    std::cout
        << "This is not a valid command. Valid commands are: ADD, SEARCH, EXIT"
        << std::endl;
  }

  if (std::cin.fail())
    std::cout << std::endl;
  std::cout << "Burning the phone book, was a great time..." << std::endl;
}

int main() {
  PhoneBook phone_book;

  start_game(phone_book);
}
