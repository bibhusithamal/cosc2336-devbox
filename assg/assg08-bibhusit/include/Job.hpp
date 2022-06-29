/** @file Job.hpp
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
#ifndef _JOB_HPP_
#define _JOB_HPP_
#include <string>

using namespace std;

/** @class Job
 * @brief Example Job class that defines a job with a priority
 *   and other attributes.
 *
 * Class for job scheduling simulation.  A Job enters a system
 * at random intervals (determined by the JobSchedulerSimulator on
 * a random Poisson basis).  A job has a priority level and a serviceTime
 * which is the amount of system time it needs in order to complete
 * it task.  The main property to keep track of for jobs in a
 * simulation is how long they have to wait before they are selected
 * to be processed/run by the system.  Jobs keep track of their cost,
 * which can be used to measure a particular system's performance
 * (lower costs mean the system performed well, higher costs mean the
 * system performed more poorly).  For systems with priority based jobs,
 * the measure of the cost is determined of the function a job spent
 * waiting, and how high of a priority the job had.  We use the
 * simple calculation of cost = priority * waitTime to calculate
 * the cost for a job once it completes.
 */
class Job
{
public:
  Job();
  Job(int priority, int serviceTime, int startTime, int id);

  void setEndTime(int endTime);
  int getId() const;
  int getServiceTime() const;
  int getPriority() const;
  int getWaitTime() const;
  int getCost() const;

  bool operator==(const Job& rhs) const;
  bool operator<(const Job& rhs) const;
  bool operator>(const Job& rhs) const;
  bool operator<=(const Job& rhs) const;
  bool operator!=(const Job& rhs) const;

  string str() const;
  friend ostream& operator<<(ostream& out, const Job& aJob);

private:
  /// @brief nextListId A static int variable, used to assign unique ids
  ///   when processes are created, for identification purposes.
  static int nextListId;

  /// @brief id The actual unique id assigned to a job object.
  int id;

  /// @brief priority This jobs priority level.  Higher numbers mean higher
  ///   priority jobs in this simulation.
  int priority;

  /// @brief serviceTime The amount of system time this job needs in order to
  //    complete its task.
  int serviceTime;

  /// @brief startTime The time when the job was created.  Also the time
  ///    when the job began waiting in a queue to be selected to run.
  int startTime;

  /// @brief endTime The time when the job finished waiting (when it was
  ///    finally selected by the system to begin execution).  The difference
  ///    between endTime - startTime determines the total waitTime for this
  ///    process (calculated by getWaitTime() accessor method).
  int endTime;
};

#endif // _JOB_HPP_
