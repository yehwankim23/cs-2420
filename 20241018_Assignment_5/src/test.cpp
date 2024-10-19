// Ye-Hwan Kim (1130720) & Sungjae Hwang (1503349)
// October 18, 2024

#include <list>

#include "pch.h"
#include "student.h"

struct DLLTest : testing::Test {
    Student* stud = new Student();
    std::list<Student> dll = stud->readStudfromFile();

    void SetUp() {}

    void TearDown() {
        delete stud;
    }
};

TEST_F(DLLTest, Size) {
    EXPECT_EQ(dll.size(), 5);
}

TEST_F(DLLTest, InsertFront) {
    Student student = Student("u2000", "Solomon", "Physics");
    dll.push_front(student);
    EXPECT_TRUE(student == *dll.begin());
}

TEST_F(DLLTest, InsertBack) {
    Student student = Student("u3000", "Rebecca", "Biology");
    dll.push_back(student);
    EXPECT_TRUE(student == *dll.rbegin());
}

TEST_F(DLLTest, DeleteFromMiddle) {
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
// insert (u3001, Tina, Chemistry) before (u3000, Rebecca)
TEST_F(DLLTest, InsertAfter) {
    Student student = Student("u3001", "Tina", "Chemistry");

    // iterate through list
    for (std::list<Student>::iterator it = dll.begin(); it != dll.end(); ++it) {
        // insert Tina if uID is u3000 or name is Rebecca
        if ((*it).getName() == "Rebecca" || (*it).getID() == "u3000") {
            dll.insert(it, student);
            break;
        }
    }

    // check if (u3001, Tina, Chemistry) is before (u3000, Rebecca)
    bool check = true;

    // iterate through list
    for (std::list<Student>::iterator it = dll.begin(); it != dll.end(); ++it) {
        // check student before Rebecca
        if ((*it).getName() == "Rebecca" || (*it).getID() == "u3000") {
            check = *(--it) == student;
            break;
        }
    }

    EXPECT_TRUE(check);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// delete first student
TEST_F(DLLTest, DeleteFront) {
    Student student = dll.front();
    dll.pop_front();
    EXPECT_FALSE(student == dll.front());
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// delete last student
TEST_F(DLLTest, DeleteBack) {
    Student student = dll.back();
    dll.pop_back();
    EXPECT_FALSE(student == dll.back());
}
