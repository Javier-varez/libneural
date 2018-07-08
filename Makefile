BUILD_DIR := build
TARGET := libneuron

SRC_FILES := \
    Src/neuron.cpp \
    Src/neuronInput.cpp \
    Src/linearNeuron.cpp

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
