/** @file Job.cpp
 * @brief Example Job class that defines a job priority.
 *
 * @author Derek Harter
 * @note   class: COSC 2336, Summer 2021
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment Queues
 * @date   June 1, 2021
 *
 * A class to test and demonstrate using PriorityQueue containers with
 * user defined types.  A Job has a priority, and boolean operators
 * like operator<() are overloaded to order jobs by their priority.
 */
#include "Job.hpp"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/**
 * A constant for the Job class, used to keep track of
 * and assign unique id's for each job created.
 */
int Job::nextListId = 1;

/**
 * @brief Job default constructor
 *
 * Default constructor for Job, needed because some Queue types
 * create an empty array of Job objects, so they need to get filled
 * with empty jobs.  We simply initialize everything to 0, as
 * Job objects created this way, without a priority or service time,
 * can't be used as real jobs in a simulation.
 */
Job::Job()
{
  this->id = nextListId++;
  this->priority = 0;
  this->serviceTime = 0;
  this->startTime = 0;
  this->endTime = 0;
}

/**
 * @brief Standard constructor
 *
 * The actual constructor that needs to be used for Jobs in a simulation.
 * The job is assigned a priority, serviceTime and we record the startTime
 * when the job arrived and began waiting on the system queue for processing.
 *
 * @param priority Each job in our simulations has a priority level.  In this
 *   Job object and simulation, the higher the number, the higher the priority
 *   of the Job.
 * @param serviceTime This is the time that the job needs to run, once it is
 *   selected/scheduled by the system dispatcher to be executed.  This represents
 *   the time the system is busy processing this Job once it starts running.
 * @param startTime The system time at which this jobs was created.  Also will be
 *   the system time this job was added to a job queue in the system and began
 *   waiting to be executed.
 * @param id The unique identifier for the new job.
 */
Job::Job(int priority, int serviceTime, int startTime, int id)
{
  this->id = id;
  this->priority = priority;
  this->serviceTime = serviceTime;
  this->startTime = startTime;
  this->endTime = startTime;
}

/**
 * @brief Set endTime
 *
 * Setter method to set the endTime of this Job.  This is actually the endTime
 * of when the job stoped waiting and began executing (not the time when the job
 * was finished).  The endTime - startTime gives the total waitTime this job
 * spent waiting.
 *
 * @param endTime The time when job stoped waiting on a queue and began executing.
 */
void Job::setEndTime(int endTime)
{
  this->endTime = endTime;
}

/**
 * @brief Get job id
 *
 * Getter method to return this Job's id.  Used for display purposes.
 *
 * @returns int The unique id of this Job is returned.
 */
int Job::getId() const
{
  return id;
}

/**
 * @brief Service time getter
 *
 * Getter method to return this Job's service time.  Service time
 * is the amount of time this job needs from the system to complete
 * its task.
 *
 * @returns int The serviceTime for this Job is returned.
 */
int Job::getServiceTime() const
{
  return serviceTime;
}

/**
 * @brief Priority getter
 *
 * Getter method to return this Job's priority level.  Priority
 * is a measure of the job importance.  In this simulation, higher
 * priority means higher importance.
 *
 * @returns int The priority level for this Job is returned.
 */
int Job::getPriority() const
{
  return priority;
}

/**
 * @brief waitTime getter
 *
 * Getter method to return this Job's waitTime.  Wait time is
 * the difference from the endTime when the job stoped waiting
 * (and began executing) and startTime when the job was created
 * and began waiting to get access to the system for execution.
 *
 * @returns int The wait time for this Job is returned.  Wait time
 *   is not valid until after the job as exited the wait queue, and
 *   its endTime has been set.
 */
int Job::getWaitTime() const
{
  return endTime - startTime;
}

/**
 * @brief Cost getter
 *
 * Getter method to return this Job's cost.  Cost is a measure of
 * used to evaluate how well a particular system performs in
 * processing jobs.  In this simulation, we want to minimize time
 * high priority jobs spend waiting, and maximize high priority
 * job throughput.  Thus cost is a combination of priority and how
 * long the job spent waiting to be processed.  Since higher numbers
 * are used to mean higher priorities, multiplying the wait time
 * times the priority scales the cost so that high priority jobs
 * that have to wait for long periods have high costs.  In the
 * system, we want to minimize cost as a measure of performance.
 *
 * @returns int The cost for this Job is returned.  Cost is a measure
 *   of performance with regards to this parcitular jobs.  Cost is
 *   measured in this system as the job priority times the time the
 *   job was forced to wait before it could start executing.
 */
int Job::getCost() const
{
  return priority * getWaitTime();
}

/**
 * @brief Overload boolean equal comparison
 *
 * Overload boolean comparison between jobs.  The main purpose of
 * providing boolean comparisons between jobs in this simulation is
 * so that priority based schedulers can order the jobs based on
 * priority level, from lowest priority to highest priority.  Thus
 * for a Job, jobs are equal when they have equal priorities.
 *
 * @param rhs The Job object on the right hand side of the boolean
 *   comparison.
 *
 * @returns bool True if the two jobs have equal priority, false
 *   otherwise.
 */
bool Job::operator==(const Job& rhs) const
{
  return this->priority == rhs.priority;
}

/**
 * @brief Overload boolean less than
 *
 * Overload boolean less than comparison between jobs.  The main
 * purpose of providing boolean comparisons between jobs in this
 * simulation is so that priority based schedulers can order the jobs
 * based on priority level, from lowest priority to highest priority.
 * Thus for a Job, a job is less than another job if its priority
 * is smaller.
 *
 * @param rhs The Job object on the right hand side of the boolean
 *   comparison.
 *
 * @returns bool True if this job has lower priority than the rhs
 *   job, false otherwise.
 */
bool Job::operator<(const Job& rhs) const
{
  return this->priority < rhs.priority;
}

/**
 * @brief Overload boolean greater than
 *
 * Overload boolean greater than comparison between jobs.  The main
 * purpose of providing boolean comparisons between jobs in this
 * simulation is so that priority based schedulers can order the jobs
 * based on priority level, from lowest priority to highest priority.
 * Thus for a Job, a job is greater than another job if its priority
 * is bigger.
 *
 * @param rhs The Job object on the right hand side of the boolean
 *   comparison.
 *
 * @returns bool True if this job has higher priority than the rhs
 *   job, false otherwise.
 */
bool Job::operator>(const Job& rhs) const
{
  return this->priority > rhs.priority;
}

/**
 * @brief Overload boolean less than or equal
 *
 * Overload boolean less than or equal comparison between jobs.  The
 * main purpose of providing boolean comparisons between jobs in this
 * simulation is so that priority based schedulers can order the jobs
 * based on priority level, from lowest priority to highest priority.
 * Thus for a Job, a job is less than or equal another job if its
 * priority is smaller or the same.
 *
 * @param rhs The Job object on the right hand side of the boolean
 *   comparison.
 *
 * @returns bool True if this job has lower or equal priority than the
 *   rhs job, false otherwise.
 */
bool Job::operator<=(const Job& rhs) const
{
  return this->priority <= rhs.priority;
}

/**
 * @brief Overload boolean not equal
 *
 * Overload boolean not equal comparison between jobs.  The
 * main purpose of providing boolean comparisons between jobs in this
 * simulation is so that priority based schedulers can order the jobs
 * based on priority level, from lowest priority to highest priority.
 * Thus for a Job, a job is less than or equal another job if its
 * priority is smaller or the same.
 *
 * @param rhs The Job object on the right hand side of the boolean
 *   comparison.
 *
 * @returns bool True if this job is not equal in priority to the
 *   rhs job, false otherwise.
 */
bool Job::operator!=(const Job& rhs) const
{
  return this->priority != rhs.priority;
}

/**
 * @brief Job to string
 *
 * Make a string representation of this Job suitable for display.
 *
 * @returns string Returns the constructed string representation of this
 *   Job object.
 */
string Job::str() const
{
  ostringstream out;

  out << "(id: " << id << " priority: " << priority << ")";
  return out.str();
}

/**
 * @brief Overload output stream operator
 *
 * Overload the output stream operator to provide a representation
 * of this Job suitable for display.  Mainly useful for displaying
 * queue contents and for debugging purposes.
 */
ostream& operator<<(ostream& out, const Job& aJob)
{
  out << aJob.str();
  return out;
}
