#ifndef __TASK_H_
#define __TASK_H_

#include <string>
#include <vector>
#include <ctime>
#include <iostream>

using namespace std;

class Task;

enum taskLimitType {
	START_BEFORE_LIMIT,
	START_AFTER_LIMIT,
	END_BEFORE_LIMIT,
	PREREQUISITE_LIMIT
};

class TaskLimit {

	taskLimitType type;

	public:

	TaskLimit( taskLimitType t ) : type(t) {}
	virtual int check_limit( Task* t ) = 0;
};

class Task {

	Task* prev;
	Task* next;

	string location;
	string description;
	size_t duration;

	time_t start_time;

	vector<TaskLimit> limits;

	public:
		
	Task();

};

class StartBeforeLimit : public TaskLimit {
	time_t limit;
	public:
		StartBeforeLimit( time_t t ) : limit(t), TaskLimit(START_BEFORE_LIMIT) {}
};
class StartAfterLimit : public TaskLimit {
	time_t limit;
	public:
		StartAfterLimit( time_t t ) : limit(t), TaskLimit(START_AFTER_LIMIT) {}
};
class EndBeforeLimit : public TaskLimit {
	time_t limit;
	public:
		EndBeforeLimit( time_t t ) : limit(t), TaskLimit(END_BEFORE_LIMIT) {}
};
class PrerequisiteLimit : public TaskLimit {
	Task* limit;
	public:
		PrerequisiteLimit( Task* t ) : limit(t), TaskLimit(PREREQUISITE_LIMIT) {}
};

#endif
