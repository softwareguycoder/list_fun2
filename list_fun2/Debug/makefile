################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: list_fun2

dependents:
	-cd /home/bhart/git/api_core/api_core/Debug && $(MAKE) all
	-cd /home/bhart/git/common_core/common_core/Debug && $(MAKE) all
	-cd /home/bhart/git/list_core/list_core/Debug && $(MAKE) all

# Tool invocations
list_fun2: $(OBJS) $(USER_OBJS) /home/bhart/git/api_core/api_core/Debug/libapi_core.so /home/bhart/git/common_core/common_core/Debug/libcommon_core.so /home/bhart/git/list_core/list_core/Debug/liblist_core.so
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc -L"/home/bhart/git/list_core/list_core/Debug" -L"/home/bhart/git/common_core/common_core/Debug" -L"/home/bhart/git/api_core/api_core/Debug" -o "list_fun2" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) list_fun2
	-@echo ' '

.PHONY: all clean dependents
/home/bhart/git/api_core/api_core/Debug/libapi_core.so:
/home/bhart/git/common_core/common_core/Debug/libcommon_core.so:
/home/bhart/git/list_core/list_core/Debug/liblist_core.so:

-include ../makefile.targets
