#pragma once
#include <vector>
#include <string>

// Student Code Area - Implement these functions to complete the tasks
// DO NOT modify the function signatures

// Task 1: Pointer arithmetic with void pointers and casts
void* advanceVoidPointer(void* ptr, int bytes);

// Task 2: Pointer arithmetic with different integer types
int* castAndAdvance(char* ptr, int offset);

// Task 3: Pointer arithmetic with function pointers
int (* advanceFunctionPointer(int (*funcPtr)(int), int offset))(int);

// Task 4: Complex pointer arithmetic with multiple casts
double* complexPointerArithmetic(int* intPtr, long offset);

// Task 5: Pointer arithmetic with struct pointers
struct Point
{
    int x, y;
};

Point* advanceStructPointer(Point* ptr, int elements);

// Task 6: Pointer arithmetic with const pointers
const int* advanceConstPointer(const int* ptr, int offset);

// Task 7: Pointer arithmetic with volatile pointers
volatile char* advanceVolatilePointer(volatile char* ptr, int bytes);

// Task 8: Pointer arithmetic with array of pointers
int** advancePointerArray(int** ptrArray, int index);

// Task 9: Basic pointer-to-pointer assignment
void assignValueThroughPointer(int** ptrToPtr, int value);

// Task 10: Allocate memory through pointer-to-pointer
void allocateMemory(int** ptrToPtr, int size);

// Task 11: Swap pointers using pointer-to-pointer
void swapPointers(int** ptr1, int** ptr2);

// Task 12: Return multiple values through pointer-to-pointer
void getMinMax(int arr[], int size, int** minPtr, int** maxPtr);

// Task 13: Pointer-to-pointer with struct
struct Node
{
    int data;
    Node* next;
};

void insertNodeAtBeginning(Node** head, int value);

// Task 14: Pointer-to-pointer array allocation
void allocate2DArray(int*** array2D, int rows, int cols);

// Task 15: Pointer-to-pointer function pointer
void assignFunctionPointer(int (**funcPtr)(int), int choice);

// Task 16: Complex pointer-to-pointer arithmetic
void advancePointerToPointer(int*** ptrToPtrToPtr, int offset);

// Task 17: Extract wstring from vector<uint8_t>
std::wstring extractWStringFromVector(const std::vector<uint8_t>& data, size_t offset);

// Task 18: Create vector<uint8_t> from uint32_t
std::vector<uint8_t> createVectorFromUint32(uint32_t value);

// Task 19: Extract uint32_t from vector<uint8_t>
uint32_t extractUint32FromVector(const std::vector<uint8_t>& data, size_t offset);

// Task 20: Create vector<uint8_t> from POD struct
struct PODStruct
{
    uint16_t id;
    uint32_t value;
    uint8_t flags;
};

std::vector<uint8_t> createVectorFromPOD(const PODStruct& pod);

// Task 21: Extract POD struct from vector<uint8_t>
PODStruct extractPODFromVector(const std::vector<uint8_t>& data, size_t offset);

// Task 22: Convert vector<uint8_t> to vector<uint32_t>
std::vector<uint32_t> convertToUint32Vector(const std::vector<uint8_t>& data);

// Task 23: Convert vector<uint32_t> to vector<uint8_t>
std::vector<uint8_t> convertToUint8Vector(const std::vector<uint32_t>& data);

// Task 24: Insert wstring into vector<uint8_t> at offset
void insertWStringIntoVector(std::vector<uint8_t>& data, const std::wstring& str, size_t offset);

// Complex struct with nested data (used by multiple tasks)
// Note: Variable length data follows immediately after this struct in memory
struct ComplexStruct
{
    uint32_t header;
    uint16_t flags;
    uint8_t dataType;
    uint32_t dataOffset;
    uint32_t dataLength;
    uint8_t padding[4];
};

// Task 25: Extract wstring from complex struct at data offset
std::wstring extractWStringFromComplexStruct(const ComplexStruct* structPtr);

// Task 26: Extract raw data from complex struct with length validation
std::vector<uint8_t> extractRawDataFromComplexStruct(const ComplexStruct* structPtr);

// Task 27: Extract wstring from nested struct traversal
std::wstring extractWStringFromNestedStruct(const void* basePtr, uint32_t structOffset);

// Task 28: Extract variable length data with offset calculation
std::vector<uint8_t> extractVariableLengthData(const void* basePtr, uint32_t dataOffset, uint32_t dataLength);

// Task 29: Fix incorrect pointer type causing wrong data copy
// TODO: Find and fix the bug in copyDataFromBuffer function
void copyDataFromBuffer(uint8_t* destination, const uint8_t* source, size_t offset, size_t length);

// Task 30: Fix wrong pointer offset in pointer-to-pointer scenario
// TODO: Find and fix the bug in readDataWithOffset function
uint32_t readDataWithOffset(uint32_t** dataPtr, size_t offset);

// Task 31: Fix incorrect dereferencing of uint8_t* to uint32_t
// TODO: Find and fix the bug in readUint32FromBuffer function
uint32_t readUint32FromBuffer(const uint8_t* buffer, size_t offset);

// Complex data structures for advanced bug-fixing tasks
struct DataHeader
{
    uint32_t magic;
    uint16_t version;
    uint16_t flags;
    uint32_t dataSize;
    uint32_t checksum;
};

struct DataBlock
{
    uint32_t blockId;
    uint16_t blockType;
    uint16_t reserved;
    uint32_t offset;
    uint32_t length;
    uint8_t* dataPtr;
};

struct ProcessingContext
{
    DataHeader* header;
    DataBlock* blocks;
    uint32_t blockCount;
    uint8_t* buffer;
    size_t bufferSize;
    uint32_t currentOffset;
    bool isValid;
};

// Task 32: Fix complex struct traversal and pointer arithmetic bug
// TODO: Find and fix the bug in the struct traversal logic
bool traverseDataStructure(const void* basePtr, uint32_t structureSize, uint32_t* resultCount);
bool validateStructureIntegrity(const DataHeader* header, const DataBlock* blocks, uint32_t count);
uint32_t* extractDataPointers(const DataBlock* blocks, uint32_t count, uint32_t* pointerCount);
bool processDataPointers(uint32_t* pointers, uint32_t count, uint32_t* results);

// Task 33: Fix complex memory management and pointer validation bug
// TODO: Find and fix the bug in the memory management system
bool allocateProcessingContext(ProcessingContext** context, size_t bufferSize);
bool initializeDataBlocks(ProcessingContext* context, uint32_t blockCount);
bool validateMemoryLayout(const ProcessingContext* context);
bool cleanupProcessingContext(ProcessingContext* context);
