#ifndef PDFGENERATOR_H
#define PDFGENERATOR_H

#include <podofo/podofo.h>

#include <string>

class PDFGenerator {
public:
    void createPDF(const std::string& filename, const std::string& text);
};

#endif // PDFGENERATOR_H
