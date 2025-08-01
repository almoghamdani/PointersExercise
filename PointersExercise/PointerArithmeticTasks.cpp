#include "PointerArithmeticTasks.h"
#include "StudentCode.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <iomanip>
#include <cstddef>

// Helper function for Task 3
int testFunction1(int x) { return x * 2; }
int testFunction2(int x) { return x + 10; }
int testFunction3(int x) { return x - 5; }

// Helper functions (no longer used after task updates)
// int multiplyBy2(int x) { return x * 2; }
// int add10(int x) { return x + 10; }
// int subtract5(int x) { return x - 5; }

// Task 1: Pointer arithmetic with void pointers and casts
std::string PointerArithmeticTask1::getDescription() const
{
    return "Implement advanceVoidPointer() to advance a void pointer by bytes using casts";
}

void PointerArithmeticTask1::execute()
{
    displayTaskInfo();

    int numbers[] = {10, 20, 30, 40, 50};
    void* ptr = numbers;
    int bytes = 8; // Advance by 8 bytes (2 ints)

    std::cout << "Original void pointer points to: " << *(static_cast<int*>(ptr)) << std::endl;
    std::cout << "Advancing by " << bytes << " bytes..." << std::endl;

    // Test student implementation
    void* result = advanceVoidPointer(ptr, bytes);

    if (result != nullptr)
    {
        std::cout << "After advancing, pointer points to: " << *(static_cast<int*>(result)) << std::endl;
        bool passed = verifyResult(result == static_cast<char*>(ptr) + bytes, "Pointer correctly advanced by bytes");
        passed &= verifyResult(*(static_cast<int*>(result)) == 30, "Pointer points to correct value (30)");

        if (passed)
        {
            // Green color for success
            std::cout << "\033[32m[SUCCESS]\033[0m Task 1 completed successfully!" << std::endl;
        }
        else
        {
            // Red color for failure
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Function returned nullptr - implementation incomplete" << std::endl;
    }
}

// Task 2: Pointer arithmetic with different integer types
std::string PointerArithmeticTask2::getDescription() const
{
    return "Implement castAndAdvance() to cast char* to int* and advance by offset";
}

void PointerArithmeticTask2::execute()
{
    displayTaskInfo();

    char buffer[20];
    int* intPtr = reinterpret_cast<int*>(buffer);
    intPtr[0] = 100;
    intPtr[1] = 200;
    intPtr[2] = 300;

    char* charPtr = buffer;
    int offset = 2;

    std::cout << "Original char pointer points to buffer" << std::endl;
    std::cout << "Offset: " << offset << " ints" << std::endl;

    // Test student implementation
    int* result = castAndAdvance(charPtr, offset);

    if (result != nullptr)
    {
        std::cout << "After casting and advancing, pointer points to: " << *result << std::endl;
        bool passed = verifyResult(result == intPtr + offset, "Pointer correctly cast and advanced");
        passed &= verifyResult(*result == 300, "Pointer points to correct value (300)");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 2 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Function returned nullptr - implementation incomplete" << std::endl;
    }
}

// Task 3: Multi-dimensional array traversal with pointer arithmetic
std::string PointerArithmeticTask3::getDescription() const
{
    return "Implement traverse2DArrayDiagonal() to traverse a 2D array diagonally using pointer arithmetic";
}

void PointerArithmeticTask3::execute()
{
    displayTaskInfo();

    // Create a 3x3 2D array
    int** array2D = new int*[3];
    for (int i = 0; i < 3; ++i)
    {
        array2D[i] = new int[3];
        for (int j = 0; j < 3; ++j)
        {
            array2D[i][j] = i * 3 + j + 1; // Fill with 1-9
        }
    }

    std::cout << "2D Array (3x3):" << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << array2D[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Expected diagonal sum: 1 + 5 + 9 = 15" << std::endl;

    // Test student implementation
    int result = traverse2DArrayDiagonal(array2D, 3, 3);

    std::cout << "Diagonal sum result: " << result << std::endl;
    bool passed = verifyResult(result == 15, "Correct diagonal sum calculated");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 3 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }

    // Cleanup
    for (int i = 0; i < 3; ++i)
    {
        delete[] array2D[i];
    }
    delete[] array2D;
}

// Task 4: Bit manipulation with pointer arithmetic
std::string PointerArithmeticTask4::getDescription() const
{
    return "Implement setBitsInArray() to set specific bits in a uint32_t array using pointer arithmetic";
}

void PointerArithmeticTask4::execute()
{
    displayTaskInfo();

    uint32_t array[4] = {0x00000000, 0x00000000, 0x00000000, 0x00000000};
    uint32_t bitMask = 0x0000FF00; // Set bits 8-15
    size_t startIndex = 1; // Start from second element

    std::cout << "Original array: ";
    for (size_t i = 0; i < 4; ++i)
    {
        std::cout << "0x" << std::hex << array[i] << " ";
    }
    std::cout << std::dec << std::endl;
    std::cout << "Bit mask: 0x" << std::hex << bitMask << std::dec << std::endl;
    std::cout << "Start index: " << startIndex << std::endl;

    // Test student implementation
    setBitsInArray(array, 4, bitMask, startIndex);

    std::cout << "After setting bits: ";
    for (size_t i = 0; i < 4; ++i)
    {
        std::cout << "0x" << std::hex << array[i] << " ";
    }
    std::cout << std::dec << std::endl;

    bool passed = verifyResult(array[0] == 0x00000000, "First element unchanged");
    passed &= verifyResult(array[1] == 0x0000FF00, "Second element has bits set");
    passed &= verifyResult(array[2] == 0x0000FF00, "Third element has bits set");
    passed &= verifyResult(array[3] == 0x0000FF00, "Fourth element has bits set");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 4 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 5: String manipulation with pointer arithmetic
std::string PointerArithmeticTask5::getDescription() const
{
    return "Implement reverseStringInPlace() to reverse a string using pointer arithmetic";
}

void PointerArithmeticTask5::execute()
{
    displayTaskInfo();

    char str[] = "Hello World";
    std::cout << "Original string: " << str << std::endl;

    // Test student implementation
    reverseStringInPlace(str);

    std::cout << "Reversed string: " << str << std::endl;
    bool passed = verifyResult(strcmp(str, "dlroW olleH") == 0, "String correctly reversed");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 5 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 6: Memory layout analysis with pointer arithmetic
std::string PointerArithmeticTask6::getDescription() const
{
    return "Implement extractValueFromMemoryLayout() to extract uint32_t value from memory layout";
}

void PointerArithmeticTask6::execute()
{
    displayTaskInfo();

    MemoryLayoutStruct data = {0x12, 0x3456, 0x789ABCDE, 0x123456789ABCDEF0};
    size_t offset = offsetof(MemoryLayoutStruct, value); // Offset to value field

    std::cout << "Memory layout struct:" << std::endl;
    std::cout << "flags: 0x" << std::hex << (int)data.flags << std::dec << std::endl;
    std::cout << "id: 0x" << std::hex << data.id << std::dec << std::endl;
    std::cout << "value: 0x" << std::hex << data.value << std::dec << std::endl;
    std::cout << "timestamp: 0x" << std::hex << data.timestamp << std::dec << std::endl;
    std::cout << "Offset to value field: " << offset << " bytes" << std::endl;

    // Test student implementation
    uint32_t result = extractValueFromMemoryLayout(&data, offset);

    std::cout << "Extracted value: 0x" << std::hex << result << std::dec << std::endl;
    bool passed = verifyResult(result == 0x789ABCDE, "Correct value extracted from memory layout");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 6 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 7: Function pointer table traversal
std::string PointerArithmeticTask7::getDescription() const
{
    return "Implement executeFunctionTable() to traverse and execute function pointers";
}

void PointerArithmeticTask7::execute()
{
    displayTaskInfo();

    // Define math functions
    auto add = [](int a, int b) -> int { return a + b; };
    auto multiply = [](int a, int b) -> int { return a * b; };
    auto subtract = [](int a, int b) -> int { return a - b; };

    MathFunction funcTable[] = {add, multiply, subtract};
    int a = 10, b = 5;

    std::cout << "Function table: [add, multiply, subtract]" << std::endl;
    std::cout << "Input: a=" << a << ", b=" << b << std::endl;
    std::cout << "Expected: add(10,5) + multiply(10,5) + subtract(10,5) = 15 + 50 + 5 = 70" << std::endl;

    // Test student implementation
    int result = executeFunctionTable(funcTable, 3, a, b);

    std::cout << "Result: " << result << std::endl;
    bool passed = verifyResult(result == 70, "Correct function table execution");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 7 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 8: First set bit search in uint32_t array
std::string PointerArithmeticTask8::getDescription() const
{
    return "Implement findFirstSetBitIndex() to find first set bit and return byte index";
}

void PointerArithmeticTask8::execute()
{
    displayTaskInfo();

    uint32_t array[] = {0x00000000, 0x00000000, 0x08000000, 0x00000000}; // Bit 3 set in third element
    size_t size = 4;

    std::cout << "Array: ";
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << "0x" << std::hex << array[i] << " ";
    }
    std::cout << std::dec << std::endl;
    std::cout << "Expected: First set bit is at bit 67 (byte 8 + 3 = 11)" << std::endl;

    // Test student implementation
    size_t result = findFirstSetBitIndex(array, size);

    std::cout << "First set bit found at byte index: " << result << std::endl;
    bool passed = verifyResult(result == 11, "Correct byte index for first set bit");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 8 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 9: Basic pointer-to-pointer assignment
std::string PointerArithmeticTask9::getDescription() const
{
    return "Implement assignValueThroughPointer() to assign a value through a pointer-to-pointer";
}

void PointerArithmeticTask9::execute()
{
    displayTaskInfo();

    int value = 42;
    int* ptr = &value;
    int** ptrToPtr = &ptr;
    int newValue = 100;

    std::cout << "Original value: " << **ptrToPtr << std::endl;
    std::cout << "New value to assign: " << newValue << std::endl;

    // Test student implementation
    assignValueThroughPointer(ptrToPtr, newValue);

    std::cout << "After assignment: " << **ptrToPtr << std::endl;
    bool passed = verifyResult(**ptrToPtr == newValue, "Value correctly assigned through pointer-to-pointer");
    passed &= verifyResult(*ptr == newValue, "Value correctly stored in the pointed variable");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 9 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 10: Allocate memory through pointer-to-pointer
std::string PointerArithmeticTask10::getDescription() const
{
    return "Implement findPointerWithBitsSet() to search for a pointer pointing to a value with specific bits set";
}

void PointerArithmeticTask10::execute()
{
    displayTaskInfo();

    // Create test data with various bit patterns
    uint32_t values[] = {
        0x00000000,
        0x0000000F,
        0x000000F0,
        0x00000F00,
        0x0000F000,
        0x000F0000,
        0x00F00000,
        0x0F000000
    };
    uint32_t* pointers[8];

    for (size_t i = 0; i < 8; ++i)
    {
        pointers[i] = &values[i];
    }

    uint32_t requiredBits = 0x0000000F; // Look for values with bits 0-3 set
    size_t foundIndex = 0;
    uint32_t otherBitsSet = 0;

    std::cout << "Searching for pointer to value with bits 0x" << std::hex << requiredBits << " set" << std::dec <<
            std::endl;
    std::cout << "Values in array: ";
    for (size_t i = 0; i < 8; ++i)
    {
        std::cout << "0x" << std::hex << values[i] << " ";
    }
    std::cout << std::dec << std::endl;

    // Test student implementation
    bool found = findPointerWithBitsSet(pointers, 8, requiredBits, &foundIndex, &otherBitsSet);

    if (found)
    {
        std::cout << "Found pointer at index: " << foundIndex << std::endl;
        std::cout << "Value at that pointer: 0x" << std::hex << values[foundIndex] << std::dec << std::endl;
        std::cout << "Other bits set: 0x" << std::hex << otherBitsSet << std::dec << std::endl;

        bool passed = verifyResult(foundIndex == 1, "Correct index found (value 0x0000000F)");
        passed &= verifyResult(otherBitsSet == 0x00000000, "No other bits set in the found value");
        passed &= verifyResult((values[foundIndex] & requiredBits) == requiredBits, "Required bits are actually set");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 10 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m No pointer found - implementation incomplete" << std::endl;
    }
}

// Task 11: Swap pointers using pointer-to-pointer
std::string PointerArithmeticTask11::getDescription() const
{
    return "Implement swapPointers() to swap the pointers that ptr1 and ptr2 point to";
}

void PointerArithmeticTask11::execute()
{
    displayTaskInfo();

    int a = 10, b = 20;
    int* ptr1 = &a;
    int* ptr2 = &b;
    int** ptrToPtr1 = &ptr1;
    int** ptrToPtr2 = &ptr2;

    std::cout << "Before swap: ptr1 points to " << **ptrToPtr1 << ", ptr2 points to " << **ptrToPtr2 << std::endl;

    // Test student implementation
    swapPointers(ptrToPtr1, ptrToPtr2);

    std::cout << "After swap: ptr1 points to " << **ptrToPtr1 << ", ptr2 points to " << **ptrToPtr2 << std::endl;
    bool passed = verifyResult(**ptrToPtr1 == 20, "ptr1 now points to the value that ptr2 originally pointed to");
    passed &= verifyResult(**ptrToPtr2 == 10, "ptr2 now points to the value that ptr1 originally pointed to");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 11 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 12: Return multiple values through pointer-to-pointer
std::string PointerArithmeticTask12::getDescription() const
{
    return "Implement getMinMax() to find min and max values and assign them through pointers";
}

void PointerArithmeticTask12::execute()
{
    displayTaskInfo();

    int arr[] = {5, 2, 8, 1, 9, 3};
    int size = 6;
    int* minPtr = nullptr;
    int* maxPtr = nullptr;
    int** ptrToMinPtr = &minPtr;
    int** ptrToMaxPtr = &maxPtr;

    std::cout << "Array: [5, 2, 8, 1, 9, 3]" << std::endl;
    std::cout << "Expected min: 1, Expected max: 9" << std::endl;

    // Test student implementation
    getMinMax(arr, size, ptrToMinPtr, ptrToMaxPtr);

    if (minPtr != nullptr && maxPtr != nullptr)
    {
        std::cout << "Found min: " << *minPtr << " at index " << (minPtr - arr) << std::endl;
        std::cout << "Found max: " << *maxPtr << " at index " << (maxPtr - arr) << std::endl;

        bool passed = verifyResult(*minPtr == 1, "Minimum value correctly found");
        passed &= verifyResult(*maxPtr == 9, "Maximum value correctly found");
        passed &= verifyResult(minPtr >= arr && minPtr < arr + size, "Min pointer points to valid array element");
        passed &= verifyResult(maxPtr >= arr && maxPtr < arr + size, "Max pointer points to valid array element");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 12 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Function failed to assign pointers - implementation incomplete" <<
                std::endl;
    }
}

// Task 13: Pointer-to-pointer with struct
std::string PointerArithmeticTask13::getDescription() const
{
    return "Implement insertNodeAtBeginning() to insert a new node at the beginning of a linked list";
}

void PointerArithmeticTask13::execute()
{
    displayTaskInfo();

    Node* head = nullptr;
    Node** headPtr = &head;
    int value = 42;

    std::cout << "Original head: " << (head == nullptr ? "nullptr" : "not nullptr") << std::endl;
    std::cout << "Inserting value: " << value << std::endl;

    // Test student implementation
    insertNodeAtBeginning(headPtr, value);

    if (head != nullptr)
    {
        std::cout << "After insertion: head points to node with value " << head->data << std::endl;
        bool passed = verifyResult(head->data == value, "New node has correct value");
        passed &= verifyResult(head->next == nullptr, "New node's next pointer is nullptr");

        // Insert another node
        insertNodeAtBeginning(headPtr, 100);
        passed &= verifyResult(head->data == 100, "Second insertion works correctly");
        passed &= verifyResult(head->next->data == value, "Second node points to first node");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 13 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }

        // Clean up
        delete head->next;
        delete head;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Node insertion failed - implementation incomplete" << std::endl;
    }
}

// Task 14: Complex pointer-to-pointer linked list manipulation
std::string PointerArithmeticTask14::getDescription() const
{
    return "Implement reverseLinkedList() to reverse a linked list in-place using pointer-to-pointer";
}

void PointerArithmeticTask14::execute()
{
    displayTaskInfo();

    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode{1, nullptr};
    ListNode* current = head;
    for (int i = 2; i <= 5; ++i)
    {
        current->next = new ListNode{i, nullptr};
        current = current->next;
    }

    std::cout << "Original list: ";
    current = head;
    while (current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;

    ListNode** headPtr = &head;
    int nodeCount = reverseLinkedList(headPtr);

    std::cout << "Reversed list: ";
    current = head;
    while (current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
    std::cout << "Nodes processed: " << nodeCount << std::endl;

    bool passed = verifyResult(nodeCount == 5, "Correct number of nodes processed");

    // Verify the list is reversed: 5 -> 4 -> 3 -> 2 -> 1
    current = head;
    int expectedValues[] = {5, 4, 3, 2, 1};
    for (int i = 0; i < 5; ++i)
    {
        if (current == nullptr || current->value != expectedValues[i])
        {
            passed = false;
            break;
        }
        current = current->next;
    }
    passed &= verifyResult(current == nullptr, "List properly terminated");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 14 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }

    // Clean up
    while (head != nullptr)
    {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// Task 15: Pointer-to-pointer dynamic array management
std::string PointerArithmeticTask15::getDescription() const
{
    return "Implement addToDynamicArray() to manage a dynamic array with pointer-to-pointer";
}

void PointerArithmeticTask15::execute()
{
    displayTaskInfo();

    DynamicArray* array = new DynamicArray{nullptr, 0, 0};
    DynamicArray** arrayPtr = &array;

    std::cout << "Initial array - size: " << array->size << ", capacity: " << array->capacity << std::endl;

    // Add several values to test dynamic growth
    int values[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int numValues = 10;

    for (int i = 0; i < numValues; ++i)
    {
        bool success = addToDynamicArray(arrayPtr, values[i]);
        if (!success)
        {
            std::cout << "Failed to add value " << values[i] << std::endl;
            break;
        }
    }

    std::cout << "After adding " << numValues << " values:" << std::endl;
    std::cout << "Array size: " << array->size << std::endl;
    std::cout << "Array capacity: " << array->capacity << std::endl;

    if (array->data != nullptr)
    {
        std::cout << "Array contents: ";
        for (size_t i = 0; i < array->size; ++i)
        {
            std::cout << array->data[i] << " ";
        }
        std::cout << std::endl;
    }

    bool passed = verifyResult(array->size == numValues, "All values were added");
    passed &= verifyResult(array->capacity >= array->size, "Capacity is sufficient");
    passed &= verifyResult(array->data != nullptr, "Array data was allocated");

    if (passed)
    {
        // Verify all values are correct
        for (int i = 0; i < numValues; ++i)
        {
            if (array->data[i] != values[i])
            {
                passed = false;
                break;
            }
        }
        passed &= verifyResult(true, "All values are correct");
    }

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 15 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }

    // Clean up
    if (array->data != nullptr)
    {
        delete[] array->data;
    }
    delete array;
}

// Task 16: Complex pointer-to-pointer matrix manipulation
std::string PointerArithmeticTask16::getDescription() const
{
    return "Implement transposeMatrixInPlace() to transpose a 2D matrix in-place using pointer arithmetic";
}

void PointerArithmeticTask16::execute()
{
    displayTaskInfo();

    // Create a 3x3 matrix
    Matrix2D* matrix = new Matrix2D();
    matrix->rows = 3;
    matrix->cols = 3;
    matrix->data = new int*[3];

    for (int i = 0; i < 3; ++i)
    {
        matrix->data[i] = new int[3];
        for (int j = 0; j < 3; ++j)
        {
            matrix->data[i][j] = i * 3 + j + 1; // Fill with 1-9
        }
    }

    std::cout << "Original 3x3 matrix:" << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << matrix->data[i][j] << " ";
        }
        std::cout << std::endl;
    }

    Matrix2D** matrixPtr = &matrix;

    // Test student implementation
    bool result = transposeMatrixInPlace(matrixPtr);

    if (result && matrix != nullptr)
    {
        std::cout << "Transposed matrix:" << std::endl;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                std::cout << matrix->data[i][j] << " ";
            }
            std::cout << std::endl;
        }

        // Verify transposition: original[i][j] should equal transposed[j][i]
        bool passed = true;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                int expected = (j * 3 + i + 1); // Expected transposed value
                if (matrix->data[i][j] != expected)
                {
                    passed = false;
                    break;
                }
            }
        }

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 16 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Function returned false - implementation incomplete" << std::endl;
    }

    // Cleanup
    if (matrix != nullptr)
    {
        for (int i = 0; i < 3; ++i)
        {
            delete[] matrix->data[i];
        }
        delete[] matrix->data;
        delete matrix;
    }
}

// Task 17: Extract wstring from vector<uint8_t>
std::string PointerArithmeticTask17::getDescription() const
{
    return "Implement extractWStringFromVector() to extract a wstring from a vector at the given offset";
}

void PointerArithmeticTask17::execute()
{
    displayTaskInfo();

    std::vector<uint8_t> data(50, 0);
    std::wstring testString = L"Hello World";
    size_t offset = 10;

    // Copy wstring data to vector at offset
    std::memcpy(&data[offset], testString.data(), testString.size() * sizeof(wchar_t));

    std::cout << "Vector size: " << data.size() << std::endl;
    std::cout << "Offset: " << offset << std::endl;
    std::cout << "Expected string: " << testString.c_str() << std::endl;

    // Test student implementation
    std::wstring result = extractWStringFromVector(data, offset);

    std::cout << "Extracted string: " << result.c_str() << std::endl;
    bool passed = verifyResult(result == testString, "Correctly extracted wstring from vector");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 17 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 18: Create vector<uint8_t> from uint32_t
std::string PointerArithmeticTask18::getDescription() const
{
    return "Implement createVectorFromUint32() to create a vector from a uint32_t value";
}

void PointerArithmeticTask18::execute()
{
    displayTaskInfo();

    uint32_t testValue = 0x12345678;

    std::cout << "Input uint32_t: 0x" << std::hex << testValue << std::dec << std::endl;

    // Test student implementation
    std::vector<uint8_t> result = createVectorFromUint32(testValue);

    std::cout << "Result vector size: " << result.size() << std::endl;
    std::cout << "Expected size: " << sizeof(uint32_t) << std::endl;

    bool passed = verifyResult(result.size() == sizeof(uint32_t), "Vector has correct size");

    if (passed)
    {
        uint32_t extractedValue;
        std::memcpy(&extractedValue, result.data(), sizeof(uint32_t));
        passed &= verifyResult(extractedValue == testValue, "Vector contains correct uint32_t value");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 18 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 19: Extract uint32_t from vector<uint8_t>
std::string PointerArithmeticTask19::getDescription() const
{
    return "Implement extractUint32FromVector() to extract a uint32_t from a vector at the given offset";
}

void PointerArithmeticTask19::execute()
{
    displayTaskInfo();

    std::vector<uint8_t> data(20, 0);
    uint32_t testValue = 0xABCD1234;
    size_t offset = 5;

    // Copy uint32_t to vector at offset
    std::memcpy(&data[offset], &testValue, sizeof(uint32_t));

    std::cout << "Vector size: " << data.size() << std::endl;
    std::cout << "Offset: " << offset << std::endl;
    std::cout << "Expected value: 0x" << std::hex << testValue << std::dec << std::endl;

    // Test student implementation
    uint32_t result = extractUint32FromVector(data, offset);

    std::cout << "Extracted value: 0x" << std::hex << result << std::dec << std::endl;
    bool passed = verifyResult(result == testValue, "Correctly extracted uint32_t from vector");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 19 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 20: Create vector<uint8_t> from POD struct
std::string PointerArithmeticTask20::getDescription() const
{
    return "Implement createVectorFromPOD() to create a vector from a POD struct";
}

void PointerArithmeticTask20::execute()
{
    displayTaskInfo();

    PODStruct testPod = {0x1234, 0x567890AB, 0xCD};

    std::cout << "Input POD - ID: 0x" << std::hex << testPod.id
            << ", Value: 0x" << testPod.value
            << ", Flags: 0x" << (int)testPod.flags << std::dec << std::endl;

    // Test student implementation
    std::vector<uint8_t> result = createVectorFromPOD(testPod);

    std::cout << "Result vector size: " << result.size() << std::endl;
    std::cout << "Expected size: " << sizeof(PODStruct) << std::endl;

    bool passed = verifyResult(result.size() == sizeof(PODStruct), "Vector has correct size");

    if (passed)
    {
        PODStruct extractedPod;
        std::memcpy(&extractedPod, result.data(), sizeof(PODStruct));
        passed &= verifyResult(extractedPod.id == testPod.id, "POD ID correctly stored");
        passed &= verifyResult(extractedPod.value == testPod.value, "POD value correctly stored");
        passed &= verifyResult(extractedPod.flags == testPod.flags, "POD flags correctly stored");

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 20 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 21: Extract POD struct from vector<uint8_t>
std::string PointerArithmeticTask21::getDescription() const
{
    return "Implement extractPODFromVector() to extract a POD struct from a vector at the given offset";
}

void PointerArithmeticTask21::execute()
{
    displayTaskInfo();

    std::vector<uint8_t> data(30, 0);
    PODStruct testPod = {0xABCD, 0x12345678, 0xEF};
    size_t offset = 8;

    // Copy POD to vector at offset
    std::memcpy(&data[offset], &testPod, sizeof(PODStruct));

    std::cout << "Vector size: " << data.size() << std::endl;
    std::cout << "Offset: " << offset << std::endl;
    std::cout << "Expected POD - ID: 0x" << std::hex << testPod.id
            << ", Value: 0x" << testPod.value
            << ", Flags: 0x" << (int)testPod.flags << std::dec << std::endl;

    // Test student implementation
    PODStruct result = extractPODFromVector(data, offset);

    std::cout << "Extracted POD - ID: 0x" << std::hex << result.id
            << ", Value: 0x" << result.value
            << ", Flags: 0x" << (int)result.flags << std::dec << std::endl;

    bool passed = verifyResult(result.id == testPod.id, "POD ID correctly extracted");
    passed &= verifyResult(result.value == testPod.value, "POD value correctly extracted");
    passed &= verifyResult(result.flags == testPod.flags, "POD flags correctly extracted");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 21 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 22: Convert vector<uint8_t> to vector<uint32_t>
std::string PointerArithmeticTask22::getDescription() const
{
    return "Implement convertToUint32Vector() to convert a vector of uint8_t to uint32_t";
}

void PointerArithmeticTask22::execute()
{
    displayTaskInfo();

    std::vector<uint8_t> data = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0};
    std::vector<uint32_t> expected = {0x78563412, 0xF0DEBC9A}; // Little-endian

    std::cout << "Input vector size: " << data.size() << std::endl;
    std::cout << "Expected uint32_t count: " << expected.size() << std::endl;

    // Test student implementation
    std::vector<uint32_t> result = convertToUint32Vector(data);

    std::cout << "Result vector size: " << result.size() << std::endl;

    bool passed = verifyResult(result.size() == expected.size(), "Vector has correct size");

    if (passed)
    {
        for (size_t i = 0; i < result.size(); ++i)
        {
            std::cout << "Result[" << i << "]: 0x" << std::hex << result[i]
                    << ", Expected: 0x" << expected[i] << std::dec << std::endl;
            passed &= verifyResult(result[i] == expected[i], "Value correctly converted");
        }

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 22 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 23: Convert vector<uint32_t> to vector<uint8_t>
std::string PointerArithmeticTask23::getDescription() const
{
    return "Implement convertToUint8Vector() to convert a vector of uint32_t to uint8_t";
}

void PointerArithmeticTask23::execute()
{
    displayTaskInfo();

    std::vector<uint32_t> data = {0x12345678, 0x9ABCDEF0};
    std::vector<uint8_t> expected = {0x78, 0x56, 0x34, 0x12, 0xF0, 0xDE, 0xBC, 0x9A}; // Little-endian

    std::cout << "Input vector size: " << data.size() << std::endl;
    std::cout << "Expected uint8_t count: " << expected.size() << std::endl;

    // Test student implementation
    std::vector<uint8_t> result = convertToUint8Vector(data);

    std::cout << "Result vector size: " << result.size() << std::endl;

    bool passed = verifyResult(result.size() == expected.size(), "Vector has correct size");

    if (passed)
    {
        for (size_t i = 0; i < result.size(); ++i)
        {
            std::cout << "Result[" << i << "]: 0x" << std::hex << (int)result[i]
                    << ", Expected: 0x" << (int)expected[i] << std::dec << std::endl;
            passed &= verifyResult(result[i] == expected[i], "Value correctly converted");
        }

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 23 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 24: Insert wstring into vector<uint8_t> at offset
std::string PointerArithmeticTask24::getDescription() const
{
    return "Implement insertWStringIntoVector() to insert a wstring into a vector at the given offset";
}

void PointerArithmeticTask24::execute()
{
    displayTaskInfo();

    std::vector<uint8_t> data(50, 0);
    std::wstring testString = L"Test String";
    size_t offset = 15;

    std::cout << "Vector size: " << data.size() << std::endl;
    std::cout << "Offset: " << offset << std::endl;
    std::cout << "String to insert: " << testString.c_str() << std::endl;

    // Test student implementation
    insertWStringIntoVector(data, testString, offset);

    // Verify the insertion
    std::wstring extracted = std::wstring(reinterpret_cast<const wchar_t*>(&data[offset]));

    std::cout << "Extracted string: " << extracted.c_str() << std::endl;
    bool passed = verifyResult(extracted == testString, "String correctly inserted into vector");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 24 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 25: Complex vector data structure with variable-length fields
std::string PointerArithmeticTask25::getDescription() const
{
    return
            "Implement extractVectorDataField() to extract data from a complex vector structure with variable-length fields";
}

void PointerArithmeticTask25::execute()
{
    displayTaskInfo();

    // Create a complex vector structure with multiple fields
    std::vector<uint8_t> data;

    // Header
    VectorDataHeader header;
    header.magic = 0x12345678;
    header.version = 1;
    header.fieldCount = 3;
    header.totalSize = 0; // Will be calculated

    const auto data_start = sizeof(VectorDataHeader) + sizeof(VectorDataField) * 3;

    // Fields
    VectorDataField fields[3];
    fields[0] = {1, 0, 1001, data_start + 0, 8}; // Field 1001: 8 bytes
    fields[1] = {2, 0, 1002, data_start + 8, 16}; // Field 1002: 16 bytes  
    fields[2] = {3, 0, 1003, data_start + 24, 12}; // Field 1003: 12 bytes

    // Calculate total size
    header.totalSize = sizeof(VectorDataHeader) + sizeof(fields) + 8 + 16 + 12;

    // Build the data vector
    const uint8_t* headerPtr = reinterpret_cast<const uint8_t*>(&header);
    data.insert(data.end(), headerPtr, headerPtr + sizeof(VectorDataHeader));

    const uint8_t* fieldsPtr = reinterpret_cast<const uint8_t*>(fields);
    data.insert(data.end(), fieldsPtr, fieldsPtr + sizeof(fields));

    // Add field data
    uint8_t field1Data[] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};
    uint8_t field2Data[] = {
        0xAA,
        0xBB,
        0xCC,
        0xDD,
        0xEE,
        0xFF,
        0x00,
        0x11,
        0x22,
        0x33,
        0x44,
        0x55,
        0x66,
        0x77,
        0x88,
        0x99
    };
    uint8_t field3Data[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C};

    data.insert(data.end(), field1Data, field1Data + 8);
    data.insert(data.end(), field2Data, field2Data + 16);
    data.insert(data.end(), field3Data, field3Data + 12);

    std::cout << "Complex vector structure created with 3 fields" << std::endl;
    std::cout << "Field 1001: 8 bytes, Field 1002: 16 bytes, Field 1003: 12 bytes" << std::endl;

    // Test student implementation - extract field 1002
    std::vector<uint8_t> result = extractVectorDataField(data, 1002);

    std::cout << "Extracted field 1002 size: " << result.size() << std::endl;
    bool passed = verifyResult(result.size() == 16, "Correct field size extracted");

    if (passed)
    {
        // Verify the extracted data matches field2Data
        bool dataCorrect = true;
        for (size_t i = 0; i < 16; ++i)
        {
            if (result[i] != field2Data[i])
            {
                dataCorrect = false;
                break;
            }
        }
        passed &= verifyResult(dataCorrect, "Correct field data extracted");
    }

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 25 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 26: Multi-dimensional vector manipulation with pointer arithmetic
std::string PointerArithmeticTask26::getDescription() const
{
    return
            "Implement convertVectorToMatrix() to convert a 1D vector to a 2D matrix representation using pointer arithmetic";
}

void PointerArithmeticTask26::execute()
{
    displayTaskInfo();

    // Create a 1D vector with 9 elements (3x3 matrix)
    std::vector<uint32_t> data = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t rows = 3, cols = 3;

    std::cout << "1D vector with " << data.size() << " elements" << std::endl;
    std::cout << "Converting to " << rows << "x" << cols << " matrix" << std::endl;

    VectorMatrix* matrix = nullptr;
    VectorMatrix** matrixPtr = &matrix;

    // Test student implementation
    bool result = convertVectorToMatrix(data, rows, cols, matrixPtr);

    if (result && matrix != nullptr)
    {
        std::cout << "Matrix conversion successful" << std::endl;
        std::cout << "Matrix dimensions: " << matrix->rows << "x" << matrix->cols << std::endl;

        bool passed = verifyResult(matrix->rows == rows, "Correct number of rows");
        passed &= verifyResult(matrix->cols == cols, "Correct number of columns");
        passed &= verifyResult(matrix->data.size() == data.size(), "Data size preserved");

        if (passed)
        {
            // Verify data integrity
            bool dataCorrect = true;
            for (size_t i = 0; i < data.size(); ++i)
            {
                if (matrix->data[i] != data[i])
                {
                    dataCorrect = false;
                    break;
                }
            }
            passed &= verifyResult(dataCorrect, "Data integrity preserved");
        }

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 26 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Function returned false - implementation incomplete" << std::endl;
    }

    // Cleanup
    if (matrix != nullptr)
    {
        delete matrix;
    }
}

// Task 27: Complex vector serialization with nested structures
std::string PointerArithmeticTask27::getDescription() const
{
    return "Implement serializeNestedStruct() to serialize a complex nested structure into a vector<uint8_t>";
}

void PointerArithmeticTask27::execute()
{
    displayTaskInfo();

    // Create a nested structure
    NestedStruct nested;
    nested.id = 0x12345678;
    nested.flags = 0xABCD;
    nested.type = 42;
    nested.reserved = 0;
    nested.data = {100, 200, 300, 400, 500};

    std::cout << "Nested structure created with ID: 0x" << std::hex << nested.id << std::dec << std::endl;
    std::cout << "Data vector size: " << nested.data.size() << std::endl;

    // Test student implementation
    std::vector<uint8_t> result = serializeNestedStruct(nested);

    std::cout << "Serialized data size: " << result.size() << std::endl;
    bool passed = verifyResult(result.size() > 0, "Serialization produced data");

    if (passed)
    {
        // Verify the serialized data can be deserialized correctly
        // This is a basic verification - in a real scenario you'd have a deserialization function
        size_t expectedSize = sizeof(uint32_t) + sizeof(uint16_t) + sizeof(uint8_t) + sizeof(uint8_t) +
                sizeof(uint32_t) + nested.data.size() * sizeof(uint32_t);
        passed &= verifyResult(result.size() == expectedSize, "Correct serialized size");
    }

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 27 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 28: Vector-based binary tree serialization
std::string PointerArithmeticTask28::getDescription() const
{
    return "Implement serializeBinaryTree() and deserializeBinaryTree() using vector<uint8_t>";
}

void PointerArithmeticTask28::execute()
{
    displayTaskInfo();

    // Create a simple binary tree
    BinaryTreeNode* root = new BinaryTreeNode{10, nullptr, nullptr};
    root->left = new BinaryTreeNode{5, nullptr, nullptr};
    root->right = new BinaryTreeNode{15, nullptr, nullptr};
    root->left->left = new BinaryTreeNode{3, nullptr, nullptr};
    root->left->right = new BinaryTreeNode{7, nullptr, nullptr};

    std::cout << "Binary tree created with 5 nodes" << std::endl;

    // Test student implementation - serialize
    std::vector<uint8_t> serialized = serializeBinaryTree(root);

    bool passed = verifyResult(serialized.size() > 0, "Serialization produced data");

    if (passed)
    {
        // Test deserialization
        BinaryTreeNode* deserialized = deserializeBinaryTree(serialized);
        passed &= verifyResult(deserialized != nullptr, "Deserialization successful");

        if (passed)
        {
            // Verify tree structure (basic check)
            passed &= verifyResult(deserialized->value == 10, "Root value correct");
            passed &= verifyResult(deserialized->left != nullptr, "Left child exists");
            passed &= verifyResult(deserialized->right != nullptr, "Right child exists");
        }

        // Cleanup deserialized tree
        if (deserialized != nullptr)
        {
            // Simple cleanup - in a real implementation you'd need proper tree traversal
            delete deserialized->left->left;
            delete deserialized->left->right;
            delete deserialized->left;
            delete deserialized->right;
            delete deserialized;
        }
    }

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 28 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }

    // Cleanup original tree
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;
}

// Task 29: Complex vector data encryption
std::string PointerArithmeticTask29::getDescription() const
{
    return "Implement encryptVectorData() and decryptVectorData() using XOR encryption";
}

void PointerArithmeticTask29::execute()
{
    displayTaskInfo();

    // Create test data
    std::vector<uint8_t> originalData = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0};
    uint32_t key = 0x12345678;

    std::cout << "Original data size: " << originalData.size() << " bytes" << std::endl;
    std::cout << "Encryption key: 0x" << std::hex << key << std::dec << std::endl;

    // Test student implementation - encrypt
    EncryptedData encrypted = encryptVectorData(originalData, key);

    bool passed = verifyResult(encrypted.key == key, "Key preserved");
    passed &= verifyResult(encrypted.data.size() == originalData.size(), "Encrypted data size matches original");
    passed &= verifyResult(encrypted.checksum > 0, "Checksum calculated");

    if (passed)
    {
        // Test decryption
        std::vector<uint8_t> decrypted = decryptVectorData(encrypted, key);
        passed &= verifyResult(decrypted.size() == originalData.size(), "Decrypted size matches original");

        if (passed)
        {
            // Verify data integrity
            bool dataCorrect = true;
            for (size_t i = 0; i < originalData.size(); ++i)
            {
                if (decrypted[i] != originalData[i])
                {
                    dataCorrect = false;
                    break;
                }
            }
            passed &= verifyResult(dataCorrect, "Decrypted data matches original");
        }
    }

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 29 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 30: Extract wstring from complex struct at data offset
std::string PointerArithmeticTask30::getDescription() const
{
    return "Implement extractWStringFromComplexStruct() to extract a wstring from the data offset in a complex struct";
}

void PointerArithmeticTask30::execute()
{
    displayTaskInfo();

    // Create a test wstring
    std::wstring testString = L"Hello World from Complex Struct!";
    size_t stringSize = testString.size() * sizeof(wchar_t);

    // Allocate memory for struct + wstring data
    uint8_t* buffer = new uint8_t[sizeof(ComplexStruct) + stringSize];
    ComplexStruct* complexStruct = reinterpret_cast<ComplexStruct*>(buffer);

    // Initialize the complex struct
    complexStruct->header = 0x12345678;
    complexStruct->flags = 0xABCD;
    complexStruct->dataType = 1; // 1 = wstring data
    complexStruct->dataOffset = 0; // Data starts immediately after struct
    complexStruct->dataLength = stringSize;

    // Copy the wstring data after the struct
    uint8_t* dataPtr = buffer + sizeof(ComplexStruct);
    std::memcpy(dataPtr, testString.data(), stringSize);

    std::cout << "Complex struct header: 0x" << std::hex << complexStruct->header << std::dec << std::endl;
    std::cout << "Data type: " << (int)complexStruct->dataType << " (wstring)" << std::endl;
    std::cout << "Data length: " << complexStruct->dataLength << " bytes" << std::endl;
    std::cout << "Expected string: " << testString.c_str() << std::endl;

    // Test student implementation
    std::wstring result = extractWStringFromComplexStruct(complexStruct);

    std::cout << "Extracted string: " << result.c_str() << std::endl;
    bool passed = verifyResult(result == testString, "Correctly extracted wstring from complex struct");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 30 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }

    delete[] buffer;
}

// Task 31: Extract raw data from complex struct with length validation
std::string PointerArithmeticTask31::getDescription() const
{
    return "Implement extractRawDataFromComplexStruct() to extract raw data with length validation";
}

void PointerArithmeticTask31::execute()
{
    displayTaskInfo();

    uint8_t testData[] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC, 0xDE, 0xF0};
    size_t dataSize = sizeof(testData);

    // Allocate memory for struct + data
    uint8_t* buffer = new uint8_t[sizeof(ComplexStruct) + dataSize];
    ComplexStruct* complexStruct = reinterpret_cast<ComplexStruct*>(buffer);

    complexStruct->header = 0x87654321;
    complexStruct->flags = 0xDCBA;
    complexStruct->dataType = 2; // 2 = raw data
    complexStruct->dataOffset = 0;
    complexStruct->dataLength = dataSize;

    // Copy data after the struct
    uint8_t* dataPtr = buffer + sizeof(ComplexStruct);
    std::memcpy(dataPtr, testData, dataSize);

    std::cout << "Complex struct header: 0x" << std::hex << complexStruct->header << std::dec << std::endl;
    std::cout << "Data type: " << (int)complexStruct->dataType << " (raw data)" << std::endl;
    std::cout << "Data length: " << complexStruct->dataLength << std::endl;

    // Test student implementation
    std::vector<uint8_t> result = extractRawDataFromComplexStruct(complexStruct);

    std::cout << "Extracted data size: " << result.size() << std::endl;
    bool passed = verifyResult(result.size() == complexStruct->dataLength, "Correct data length extracted");

    if (passed)
    {
        for (size_t i = 0; i < result.size(); ++i)
        {
            std::cout << "Result[" << i << "]: 0x" << std::hex << (int)result[i]
                    << ", Expected: 0x" << (int)testData[i] << std::dec << std::endl;
            passed &= verifyResult(result[i] == testData[i], "Data correctly extracted");
        }

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 31 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }

    delete[] buffer;
}

// Task 32: Extract wstring from nested struct traversal
std::string PointerArithmeticTask32::getDescription() const
{
    return "Implement extractWStringFromNestedStruct() to extract wstring by traversing struct offsets";
}

void PointerArithmeticTask32::execute()
{
    displayTaskInfo();

    std::wstring testString1 = L"First";
    std::wstring testString2 = L"Second String";
    size_t dataSize1 = testString1.size() * sizeof(wchar_t);
    size_t dataSize2 = testString2.size() * sizeof(wchar_t);

    // Create a buffer with multiple structs + data
    size_t totalSize = 128 + sizeof(ComplexStruct) + dataSize2;
    uint8_t* buffer = new uint8_t[totalSize];
    std::memset(buffer, 0, totalSize);

    // First struct at offset 0
    ComplexStruct* struct1 = reinterpret_cast<ComplexStruct*>(buffer);
    struct1->header = 0x11111111;
    struct1->dataType = 1;
    struct1->dataOffset = 0;
    struct1->dataLength = dataSize1;

    // Copy data after first struct
    uint8_t* dataPtr1 = buffer + sizeof(ComplexStruct);
    std::memcpy(dataPtr1, testString1.data(), dataSize1);

    // Second struct at offset 128
    ComplexStruct* struct2 = reinterpret_cast<ComplexStruct*>(buffer + 128);
    struct2->header = 0x22222222;
    struct2->dataType = 1;
    struct2->dataOffset = 0;
    struct2->dataLength = dataSize2;

    // Copy data after second struct
    uint8_t* dataPtr2 = buffer + 128 + sizeof(ComplexStruct);
    std::memcpy(dataPtr2, testString2.data(), dataSize2);

    std::cout << "Buffer size: " << totalSize << std::endl;
    std::cout << "Struct offset: 128" << std::endl;
    std::cout << "Expected string: " << testString2.c_str() << std::endl;

    // Test student implementation
    std::wstring result = extractWStringFromNestedStruct(buffer, 128);

    std::cout << "Extracted string: " << result.c_str() << std::endl;
    bool passed = verifyResult(result == testString2, "Correctly extracted wstring from nested struct");

    delete[] buffer;

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 32 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 33: Extract variable length data with offset calculation
std::string PointerArithmeticTask33::getDescription() const
{
    return "Implement extractVariableLengthData() to extract data using offset and length";
}

void PointerArithmeticTask33::execute()
{
    displayTaskInfo();

    // Create a buffer with mixed data
    std::vector<uint8_t> buffer = {
        0xAA,
        0xBB,
        0xCC,
        0xDD,
        // Header
        0x11,
        0x22,
        0x33,
        0x44,
        // Some data
        0x55,
        0x66,
        0x77,
        0x88,
        // More data
        0x99,
        0xAA,
        0xBB,
        0xCC // Target data
    };

    uint32_t dataOffset = 8; // Start at byte 8
    uint32_t dataLength = 4; // Extract 4 bytes

    std::vector<uint8_t> expectedData = {0x55, 0x66, 0x77, 0x88};

    std::cout << "Buffer size: " << buffer.size() << std::endl;
    std::cout << "Data offset: " << dataOffset << std::endl;
    std::cout << "Data length: " << dataLength << std::endl;

    // Test student implementation
    std::vector<uint8_t> result = extractVariableLengthData(buffer.data(), dataOffset, dataLength);

    std::cout << "Extracted data size: " << result.size() << std::endl;
    bool passed = verifyResult(result.size() == dataLength, "Correct data length extracted");

    if (passed)
    {
        for (size_t i = 0; i < result.size(); ++i)
        {
            std::cout << "Result[" << i << "]: 0x" << std::hex << (int)result[i]
                    << ", Expected: 0x" << (int)expectedData[i] << std::dec << std::endl;
            passed &= verifyResult(result[i] == expectedData[i], "Data correctly extracted");
        }

        if (passed)
        {
            std::cout << "\033[32m[SUCCESS]\033[0m Task 33 completed successfully!" << std::endl;
        }
        else
        {
            std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        }
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 34: Fix incorrect pointer type causing wrong data copy
std::string PointerArithmeticTask34::getDescription() const
{
    return
            "Debug and fix copyDataFromBuffer() - wide character data is not being copied correctly from the source buffer";
}

void PointerArithmeticTask34::execute()
{
    displayTaskInfo();

    // Create test data with wide character content containing uppercase letters
    std::wstring testString = L"HELLO WORLD!";
    size_t wideCharSize = testString.size() * sizeof(wchar_t);

    // Create source buffer with wide character data
    uint8_t sourceBuffer[50] = {0};
    std::memcpy(sourceBuffer, testString.data(), wideCharSize);

    // Add some padding bytes after the wide character data
    for (size_t i = wideCharSize; i < 50; ++i)
    {
        sourceBuffer[i] = static_cast<uint8_t>(i);
    }

    uint8_t destinationBuffer[50] = {0};
    size_t offset = 0; // Start from beginning of wide character data
    size_t length = wideCharSize; // Copy the entire wide character string

    std::cout << "Source contains wide character string: " << testString.c_str() << std::endl;
    std::cout << "Wide character size: " << wideCharSize << " bytes" << std::endl;
    std::cout << "Offset: " << offset << std::endl;
    std::cout << "Length: " << length << " bytes" << std::endl;
    std::cout << "Expected result (lowercase): hello world!" << std::endl;

    // Test student implementation
    copyDataFromBuffer(destinationBuffer, sourceBuffer, offset, length);

    // Verify the copied data by reconstructing the wide character string
    std::wstring copiedString(reinterpret_cast<const wchar_t*>(destinationBuffer), testString.size());

    std::cout << "Copied string: " << copiedString.c_str() << std::endl;

    // Check if the string was converted to lowercase
    std::wstring expectedLowercase = L"hello world!";
    bool passed = verifyResult(copiedString == expectedLowercase,
                               "Wide character data correctly copied and converted to lowercase");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 34 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
        std::cout << "Hint: The bug is in how the wide character pointer is being advanced during copying" << std::endl;
    }
}

// Task 35: Fix wrong pointer offset in pointer-to-pointer scenario
std::string PointerArithmeticTask35::getDescription() const
{
    return "Debug and fix readDataWithOffset() - the function is reading from the wrong memory location";
}

void PointerArithmeticTask35::execute()
{
    displayTaskInfo();

    // Create test data
    uint32_t dataArray[10] = {
        0x11111111,
        0x22222222,
        0x33333333,
        0x44444444,
        0x55555555,
        0x66666666,
        0x77777777,
        0x88888888,
        0x99999999,
        0xAAAAAAAA
    };

    uint32_t* dataPtr = dataArray;
    uint32_t** ptrToPtr = &dataPtr;
    size_t offset = 3;

    std::cout << "Data array (first 8 elements): ";
    for (int i = 0; i < 8; ++i)
    {
        std::cout << "0x" << std::hex << dataArray[i] << " ";
    }
    std::cout << std::dec << std::endl;

    std::cout << "Offset: " << offset << std::endl;
    std::cout << "Expected value: 0x" << std::hex << dataArray[offset] << std::dec << std::endl;

    // Test student implementation
    uint32_t result = readDataWithOffset(ptrToPtr, offset);

    std::cout << "Read value: 0x" << std::hex << result << std::dec << std::endl;
    bool passed = verifyResult(result == dataArray[offset], "Correctly read data with offset");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 35 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 36: Fix incorrect dereferencing of uint8_t* to uint32_t
std::string PointerArithmeticTask36::getDescription() const
{
    return "Debug and fix readUint32FromBuffer() - the function is not correctly reading the uint32_t value";
}

void PointerArithmeticTask36::execute()
{
    displayTaskInfo();

    // Create test data
    uint8_t buffer[16] = {
        0x12,
        0x34,
        0x56,
        0x78,
        // First uint32_t: 0x78563412 (little endian)
        0x9A,
        0xBC,
        0xDE,
        0xF0,
        // Second uint32_t: 0xF0DEBC9A
        0x11,
        0x22,
        0x33,
        0x44,
        // Third uint32_t: 0x44332211
        0x55,
        0x66,
        0x77,
        0x88 // Fourth uint32_t: 0x88776655
    };

    size_t offset = 4; // Read second uint32_t
    uint32_t expectedValue = 0xF0DEBC9A; // Little endian

    std::cout << "Buffer (16 bytes): ";
    for (int i = 0; i < 16; ++i)
    {
        std::cout << "0x" << std::hex << (int)buffer[i] << " ";
    }
    std::cout << std::dec << std::endl;

    std::cout << "Offset: " << offset << std::endl;
    std::cout << "Expected uint32_t: 0x" << std::hex << expectedValue << std::dec << std::endl;

    // Test student implementation
    uint32_t result = readUint32FromBuffer(buffer, offset);

    std::cout << "Read uint32_t: 0x" << std::hex << result << std::dec << std::endl;
    bool passed = verifyResult(result == expectedValue, "Correctly read uint32_t from buffer");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 36 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }
}

// Task 37: Fix complex struct traversal and pointer arithmetic bug
std::string PointerArithmeticTask37::getDescription() const
{
    return "Debug and fix the struct traversal logic - data pointers are not being extracted correctly";
}

void PointerArithmeticTask37::execute()
{
    displayTaskInfo();

    // Create a data structure in memory
    size_t structureSize = sizeof(DataHeader) + (3 * sizeof(DataBlock)) + (3 * 64); // 3 blocks with 64 bytes each
    uint8_t* buffer = new uint8_t[structureSize];
    std::memset(buffer, 0, structureSize);

    // Set up header
    DataHeader* header = reinterpret_cast<DataHeader*>(buffer);
    header->magic = 0x12345678;
    header->version = 1;
    header->flags = 0;
    header->dataSize = 3 * 64; // 3 blocks of 64 bytes each
    header->checksum = 0;

    // Set up blocks
    DataBlock* blocks = reinterpret_cast<DataBlock*>(buffer + sizeof(DataHeader));
    uint8_t* dataArea = buffer + sizeof(DataHeader) + (3 * sizeof(DataBlock));

    for (int i = 0; i < 3; ++i)
    {
        blocks[i].blockId = i + 1;
        blocks[i].blockType = 1;
        blocks[i].reserved = 0;
        blocks[i].offset = i * 64;
        blocks[i].length = 64;
        blocks[i].dataPtr = dataArea + (i * 64);

        // Fill data with test values
        for (int j = 0; j < 64; ++j)
        {
            blocks[i].dataPtr[j] = static_cast<uint8_t>(i * 100 + j);
        }
    }

    std::cout << "Created data structure with 3 blocks" << std::endl;
    for (int i = 0; i < 3; ++i)
    {
        std::cout << "Block " << i << " data pointer: 0x" << std::hex << reinterpret_cast<uintptr_t>(blocks[i].dataPtr)
                << std::dec << std::endl;
    }

    uint32_t resultCount = 0;
    uint32_t* results = nullptr;
    bool success = traverseDataStructure(buffer, structureSize, &resultCount, &results);

    std::cout << "Traversal result: " << (success ? "SUCCESS" : "FAILED") << std::endl;
    std::cout << "Result count: " << resultCount << std::endl;

    // Verify that the function extracted the correct number of pointers
    bool countCorrect = (resultCount == 3);

    // Verify that the extracted pointers match the expected values
    bool pointersCorrect = true;
    if (success && countCorrect && results)
    {
        // The processDataPointers function multiplies each pointer by 2
        // So we need to check if the results match (original_pointer * 2)
        uint32_t expectedResults[3];
        for (int i = 0; i < 3; ++i)
        {
            expectedResults[i] = reinterpret_cast<uint32_t>(blocks[i].dataPtr) * 2;
        }

        // Verify that the actual results match the expected results
        std::cout << "Verifying extracted pointer values:" << std::endl;
        for (int i = 0; i < 3; ++i)
        {
            std::cout << "Block " << i << ": expected 0x" << std::hex << expectedResults[i]
                    << ", got 0x" << results[i] << std::dec << std::endl;
            if (results[i] != expectedResults[i])
            {
                pointersCorrect = false;
                std::cout << "  -> MISMATCH!" << std::endl;
                break;
            }
            else
            {
                std::cout << "  -> MATCH!" << std::endl;
            }
        }

        if (pointersCorrect)
        {
            std::cout << "All pointer values extracted correctly!" << std::endl;
        }
    }
    else if (success && countCorrect)
    {
        pointersCorrect = false;
        std::cout << "Results pointer is null but function succeeded" << std::endl;
    }

    bool passed = verifyResult(success && countCorrect && pointersCorrect,
                               "Data structure traversed correctly with proper pointer extraction");

    // Clean up the results array
    if (results)
    {
        delete[] results;
    }

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 37 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }

    delete[] buffer;
}

// Task 38: Fix complex memory management and pointer validation bug
std::string PointerArithmeticTask38::getDescription() const
{
    return "Debug and fix the memory management system - data blocks are not being allocated correctly";
}

void PointerArithmeticTask38::execute()
{
    displayTaskInfo();

    // Create a processing context
    ProcessingContext* context = nullptr;
    bool success = allocateProcessingContext(&context, 800);

    if (!success || !context)
    {
        std::cout << "\033[31m[FAILED]\033[0m Failed to allocate processing context" << std::endl;
        return;
    }

    std::cout << "Allocated processing context with buffer size: " << context->bufferSize << std::endl;
    std::cout << "Expected total data size for 5 blocks of 64 bytes each: " << (5 * 64) << " bytes" << std::endl;

    // Initialize with 5 data blocks
    success = initializeDataBlocks(context, 5);

    std::cout << "Initialization result: " << (success ? "SUCCESS" : "FAILED") << std::endl;
    std::cout << "Block count: " << context->blockCount << std::endl;
    std::cout << "Current offset: " << context->currentOffset << std::endl;

    // Debug: Show memory layout
    std::cout << "Memory layout:" << std::endl;
    for (uint32_t i = 0; i < context->blockCount; ++i)
    {
        DataBlock* block = &context->blocks[i];
        std::cout << "Block " << i << ": offset=" << block->offset
                << ", length=" << block->length
                << ", dataPtr=0x" << std::hex << reinterpret_cast<uintptr_t>(block->dataPtr) << std::dec
                << ", end=0x" << std::hex << reinterpret_cast<uintptr_t>(block->dataPtr + block->length) << std::dec <<
                std::endl;
    }

    // Check if blocks are properly allocated
    bool blocksValid = true;
    for (uint32_t i = 0; i < context->blockCount; ++i)
    {
        DataBlock* block = &context->blocks[i];
        if (block->blockId != i + 1 || block->length != 64)
        {
            blocksValid = false;
            break;
        }

        // Check if data pointer is within buffer bounds
        if (block->dataPtr < context->buffer ||
            block->dataPtr + block->length > context->buffer + context->bufferSize)
        {
            blocksValid = false;
            break;
        }

        // Check for memory overlap with previous blocks
        for (uint32_t j = 0; j < i; ++j)
        {
            DataBlock* prevBlock = &context->blocks[j];
            if (block->dataPtr >= prevBlock->dataPtr &&
                block->dataPtr < prevBlock->dataPtr + prevBlock->length)
            {
                blocksValid = false;
                break;
            }
        }

        if (!blocksValid) break;
    }

    bool passed = verifyResult(success && blocksValid, "Data blocks allocated correctly");

    if (passed)
    {
        std::cout << "\033[32m[SUCCESS]\033[0m Task 38 completed successfully!" << std::endl;
    }
    else
    {
        std::cout << "\033[31m[FAILED]\033[0m Task failed - check your implementation" << std::endl;
    }

    cleanupProcessingContext(context);
}
