#include <iostream>
#include <string>

#pragma warning (disable: 4996)


namespace constants
{
	const size_t TITLE_LENGTH = 20;
	const size_t AUTHOR_NAME_LEGTH = 30;
	const size_t LIBRARY_NAME_LENGTH = 25;
	const size_t BOOKS_CAPACITY = 10;

	const char* NO_BOOKS_FOUND = "No books found.";
}

namespace LibraryManagement
{
	enum BookStatus
	{
		Available,
		Borrowed,
		Reserved
	};

	const char* printBookStatus(BookStatus status)
	{
		switch (status)
		{
			case BookStatus::Available:
				return "Available";
			case BookStatus::Borrowed:
				return "Borrowed";
			case BookStatus::Reserved:
				return "Reserved";
			default:
				return "Unknown";
		}
	}

	struct Book
	{
		char title[constants::TITLE_LENGTH];
		char author[constants::AUTHOR_NAME_LEGTH];
		int publicationYear;
		BookStatus status;

	public:
		friend std::ostream& operator<<(std::ostream& os, const Book& b);
	};

	std::ostream& operator<<(std::ostream& os, const Book& b)
	{
		return os << b.title << " " << b.author << " " << b.publicationYear << " " << printBookStatus(b.status) << std::endl;
	}


	struct Library
	{
		char name[constants::LIBRARY_NAME_LENGTH];
		Book books[constants::BOOKS_CAPACITY];
		int bookCount = 0;
	};

	Book createBook(const char* title, const char* author, int publicationYear)
	{
		if (!title || !author)
		{
			return {};
		}

		Book book;

		strcpy(book.title, title);
		strcpy(book.author, author);
		book.publicationYear = publicationYear;
		book.status = BookStatus::Available;

		return book;
	}

	void addBook(Library& lib, const char* title, const char* author, int publicationYear)
	{
		if (lib.bookCount >= constants::BOOKS_CAPACITY)
		{
			return;
		}
		lib.books[lib.bookCount++] = createBook(title, author, publicationYear);
	}

	void borrowBook(Book& book)
	{
		if (book.status == BookStatus::Available)
		{
			book.status = BookStatus::Borrowed;
		}
	}

	void reserveBook(Book& book)
	{
		if (book.status == BookStatus::Available)
		{
			book.status = BookStatus::Reserved;
		}
	}



	void printLibrary(const Library& lib)
	{
		std::cout << "Library: " << lib.name << std::endl;
		if (lib.bookCount > 0)
		{
			for (size_t i = 0; i < lib.bookCount; i++)
			{
				std::cout << lib.books[i];
			}
		}
		else
		{
			std::cout << constants::NO_BOOKS_FOUND << std::endl;
		}
	}
}


int main()
{
	using namespace LibraryManagement;

	Library lib = { "FMI Library" };

	addBook(lib, "Under the Yoke", "Ivan Vazov", 1893);
	addBook(lib, "Tobacoo", "Dimitar Dimov", 1951);
	addBook(lib, "To Chicago and Back", "Aleko Konstantinov", 1894);

	borrowBook(lib.books[1]);
	reserveBook(lib.books[2]);

	printLibrary(lib);
}
