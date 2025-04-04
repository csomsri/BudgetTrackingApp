# Compiler
CXX = g++
CXXFLAGS = -fPIC -std=c++11 `pkg-config --cflags Qt5Widgets Qt5Sql`
LDFLAGS  = `pkg-config --libs Qt5Widgets Qt5Sql`


# Source and header files
TARGET = App

SOURCES = main.cpp mainwindow.cpp homepage.cpp analyzer.cpp
HEADERS = mainwindow.h homepage.h analyzer.h

# Auto-generate MOC files for each header that uses Q_OBJECT
MOCS = moc_mainwindow.cpp moc_homepage.cpp moc_analyzer.cpp

# Default target
all: $(TARGET)

# Generate moc files from headers
moc_%.cpp: %.h
	moc $< -o $@

# Build target
$(TARGET): $(SOURCES) $(MOCS)
	$(CXX) $(CXXFLAGS) -o $@ $(SOURCES) $(MOCS) $(LDFLAGS)

# Clean up
clean:
	rm -f $(TARGET) *.o moc_*.cpp
