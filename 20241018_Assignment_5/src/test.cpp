// Ye-Hwan Kim (1130720) & Sungjae Hwang (1503349)
// October 18, 2024

#include "gtest/gtest.h"
#include "student.h"

#include <list>

////////////////////////////////////////////////////////////////////////////////////////////////////
// provided test fixture
struct DoublyLinkedList : testing::Test {
    Student* student = new Student();
    std::list<Student> dll = student->readStudfromFile();

    void TearDown() {
        delete student;
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////
// provided tests
TEST_F(DoublyLinkedList, ProvidedSizeTest) {
    EXPECT_EQ(dll.size(), 5);
}

TEST_F(DoublyLinkedList, ProvidedInsertFrontTest) {
    Student student = Student("u2000", "Solomon", "Physics");
    dll.push_front(student);
    EXPECT_TRUE(student == *dll.begin());
}

TEST_F(DoublyLinkedList, ProvidedInsertBackTest) {
    Student student = Student("u3000", "Rebecca", "Biology");
    dll.push_back(student);
    EXPECT_TRUE(student == *dll.rbegin());
}

TEST_F(DoublyLinkedList, ProvidedDeleteFromMiddleTest) {
    for (std::list<Student>::iterator it = dll.begin(); it != dll.end(); ++it) {
        if ((*it).getID() == "u1000" && (*it).getName() == "Jess") {
            dll.erase(it);
            break;
        }
    }

    bool check = true;

    for (std::list<Student>::iterator it = dll.begin(); it != dll.end(); ++it) {
        if ((*it).getID() == "u1000" && (*it).getName() == "Jess") {
            check = false;
            break;
        }
    }

    EXPECT_TRUE(check);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// additional tests
TEST_F(DoublyLinkedList, AdditionalInsertAfterTest) {
    Student student = Student("u3001", "Tina", "Chemistry");

    // iterate through list
    for (std::list<Student>::iterator it = dll.begin(); it != dll.end(); ++it) {
        // insert (u3001, Tina, Chemistry) before (u3000, ?, ?) or (?, Rebecca, ?)
        if ((*it).getName() == "Rebecca" || (*it).getID() == "u3000") {
            dll.insert(it, student);
            break;
        }
    }

    bool check = true;

    // iterate through list
    for (std::list<Student>::iterator it = dll.begin(); it != dll.end(); ++it) {
        // check if (u3001, Tina, Chemistry) is before (u3000, ?, ?) or (?, Rebecca, ?)
        if ((*it).getName() == "Rebecca" || (*it).getID() == "u3000") {
            check = *(--it) == student;
            break;
        }
    }

    EXPECT_TRUE(check);
}

TEST_F(DoublyLinkedList, AdditionalDeleteFrontTest) {
    // delete first student
    Student student = dll.front();
    dll.pop_front();
    EXPECT_FALSE(student == dll.front());
}

TEST_F(DoublyLinkedList, AdditionalDeleteBackTest) {
    // delete last student
    Student student = dll.back();
    dll.pop_back();
    EXPECT_FALSE(student == dll.back());
}
