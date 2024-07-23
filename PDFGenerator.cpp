#include "PDFGenerator.h"

using namespace PoDoFo;


void PDFGenerator::createPDF(const std::string& filename, const std::string& text) {
    // Create a new PDF document
    PdfMemDocument document;

    // Create a new page
    auto& page = document.GetPages().CreatePage(PdfPage::CreateStandardPageSize(PdfPageSize::A4));



    // Create a painter to draw on the page
    PdfPainter painter;
    painter.SetCanvas(page);
    // painter.SetPage(page);

    // Create a font
    PdfFont* font;
    font = document.GetFonts().SearchFont("Arial");

    // Draw the text
    painter.TextState.SetFont(*font, 18);
    painter.DrawText(text.c_str(), 100.0, 800.0);

    // Finish the page
    painter.FinishDrawing();

    // Close the document
    document.Save(filename);
}