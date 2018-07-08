##
## libneuron
## Copyright (C) 2018 AllThingsEmbedded
## 
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
## 
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.
##

BUILD_DIR := build
TARGET := libneuron

SRC_FILES := \
    Src/neuron.cpp \
    Src/neuronInput.cpp \
    Src/linearNeuron.cpp \
    Src/neuronLayer.cpp \
    Src/dummyNeuron.cpp

INC_DIRS := \
    -I./Inc

LIB_DIRS :=
LIBS := -lstdc++

WARNING_FLAGS := -Wall -Werror 
CFLAGS := $(INC_DIRS)
STD := -std=c++17


# Target Definition
OBJECTS := $(addprefix $(BUILD_DIR)/,$(patsubst %.cpp,%.o, $(SRC_FILES)))
$(BUILD_DIR)/%.o: %.cpp Makefile
	mkdir -p $(dir $@)
	gcc -c $(WARNING_FLAGS) $(CFLAGS) $(STD) -o $@ $<

$(BUILD_DIR)/$(TARGET).so: $(OBJECTS) 
	gcc -shared -fPIC -o $@ $^ $(LIBS)

all: $(BUILD_DIR)/$(TARGET).so

clean:
	rm -rf $(BUILD_DIR)

TEST_TARGET := libneuronTest
TEST_SRC_FILES := \
    Test/net.cpp

TEST_OBJECTS := $(addprefix $(BUILD_DIR)/, $(patsubst %.cpp,%.o, $(TEST_SRC_FILES)))

TEST_LIBS := -lneuron
TEST_LIBS_DIR := -L./$(BUILD_DIR)/

$(BUILD_DIR)/$(TEST_TARGET): $(BUILD_DIR)/$(TARGET).so $(TEST_OBJECTS)
	gcc $(WARNING_FLAGS) $(INC_DIRS) $(TEST_LIBS_DIR) $(LIBS_DIRS) $(STD) -o $@ $(TEST_OBJECTS) $(LIBS) $(TEST_LIBS)

test: $(BUILD_DIR)/$(TEST_TARGET)
