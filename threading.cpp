#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/thread.hpp>

void read_chunk(std::ifstream &input, std::vector<std::string> &lines, int start, int end)
{
    input.seekg(start);
    std::string line;
    while (input.tellg() < end && std::getline(input, line))
    {
        lines.push_back(line);
    }
}

void read_file(const std::string &filename, int chunk_size)
{
    std::ifstream input(filename.c_str());
    int file_size = 0;
    input.seekg(0, std::ios::end);
    file_size = input.tellg();
    input.seekg(0);

    int num_chunks = file_size / chunk_size;
    std::vector<boost::thread> threads;
    std::vector<std::vector<std::string>> results(num_chunks);

    for (int i = 0; i < num_chunks; i++)
    {
        int start = i * chunk_size;
        int end = (i + 1) * chunk_size;
        threads.push_back(boost::thread(read_chunk, boost::ref(input), boost::ref(results[i]), start, end));
    }

    for (auto &thread : threads)
    {
        thread.join();
    }

    for (const auto &lines : results)
    {
        for (const auto &line : lines)
        {
            std::cout << line << std::endl;
        }
    }

    input.close();
}

int main()
{
    std::string filename = "example.txt";
    int chunk_size = 10000;

    read_file(filename, chunk_size);

    return 0;
}
