//ReduceLib.h - contains declarations of reduce class
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "FileIO.h"
#include "framework.h"
#include "ReduceInterface.h"

using std::vector;
using std::string;
<<<<<<< HEAD
using std::ostream;

//This Section strictly used to test DLL is accessible via ReduceTest.sln
extern "C" REDUCELIB_API double Add(double a, double b);
extern "C" REDUCELIB_API double Multiply(double a, double b);
extern "C" REDUCELIB_API double AddMultiply(double a, double b);
//extern "C" REDUCELIB_API bool IsolateWord(const std::string & formattedWord, const std::string & startString, const std::string & endString, std::string & isloatedWord);
//extern "C" REDUCELIB_API bool reduce(const std::string inputString);
//extern "C" REDUCELIB_API bool parseLine(const std::string line, std::pair<std::string, uint32_t>&outputPair);
//extern "C" REDUCELIB_API bool getNumberOfInstances(std::string format, std::string delim, uint32_t & instance);
//extern "C" REDUCELIB_API bool Export(const std::string & fileName, std::pair<std::string, uint32_t>&outputPair);
//extern "C" REDUCELIB_API bool reduceFile(const std::string & folderPath, const std::string & fileName, std::string & outFile);
//extern "C" REDUCELIB_API void exportSuccess();


=======
>>>>>>> d079b46d75ed6be8ec4fb992c624265fbd9d6d99

typedef std::pair<string, int> vec;

class Reduce : public ReduceInterface 
{
public:

    //variables, method titles, constructors and destructor
    Reduce();

    Reduce(std::string OutputDirectory);
    //constructor

    Reduce(const string tMemory, size_t bufferSize);
    //with buffer memory

    ~Reduce();
    //destructor

    bool reduceFile(const std::string& folderPath, const std::string& fileName, std::string& outFile);
    //import data from sorter class
    //pass 

    void ProofDLLWorks()
    {
        std::cout << "Your were the chosen one Anikin!" << std::endl;
        std::cout << "I live my life a quarter mile at a time" << std::endl;
    }

protected:

    bool IsolateWord(const std::string& formattedWord, const std::string& startString, const std::string& endString, std::string& isloatedWord);

    bool reduce(const std::string inputString);

    bool parseLine(const std::string line, std::pair<std::string, uint32_t>& outputPair);

    bool getNumberOfInstances(std::string format, std::string delim, uint32_t& instance);

    bool Export(const std::string& fileName, std::pair<std::string, uint32_t>& outputPair);

    void exportSuccess();


private:

    std::vector<std::pair<string, uint32_t>> reduced_vector;
    std::string outputDirectory;
    size_t bufferLimit; //memory limits
    string intermediateDirectory; //saved to buffer
    string initialDirectory; //FileIO
    FileIOManagement IO_management; //using fileio class
    const std::string outputFileName = "ReducerOutput.txt";;

};

