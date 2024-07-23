#include <iostream>
#include "PDFGenerator.h"

int main() {
    PDFGenerator pdfGen;
     std::string filename = "output.pdf";
     std::string text = "Hello, World!";

    pdfGen.createPDF(filename, text);

    std::cout << "PDF file created successfully!" << std::endl;

    return 0;
}
