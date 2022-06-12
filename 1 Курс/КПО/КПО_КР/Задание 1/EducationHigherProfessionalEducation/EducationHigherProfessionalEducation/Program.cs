namespace EducationHigherProfessionalEducation
{
    class Program
    {
        static void Main(string[] args)
        {
            Group group = new Group();
            group.setName("181000");
            group.updateStudyYear(2);
            group.updateAmountStudents(22);

            Console.WriteLine("Is the name correct? - {0}", group.getName() == "181000");
            Console.WriteLine("Is the year of study correct? - {0}", group.getStudyYear() == 2);
            Console.WriteLine("Is the amount students correct? - {0}", group.getAmountStudents() == 22);

            Department department = new Department();
            department.setName("test");
            department.setHeadDepartmentName("Inna");
            department.setFacultyName("linguistics");
            department.holdSeminar(group);

            Audience audience = department.getNewAudience();
            audience.setTeacherName("Ivan");
            audience.setName("404");
            audience.changeGroup(group);
            audience.giveLecture();

            Exam exam = new Exam();
            exam.setTeacherName(audience.getTeacherName());
            exam.startExam();
            Console.WriteLine("Exam grade is 10? - {0}", exam.turnAnswers(new List<bool>() {true, true, false, true}) == 10);
            exam.finishExam();

            University university = new University();
            university.setRectorName("Ivan");
            university.setName("Factorian University");
            university.deduct(group, 1);
            Console.WriteLine("amount students = 21? - {0}", group.getAmountStudents() == 21);
            university.enroll(group, 2);
            Console.WriteLine("amount students = 23? - {0}", group.getAmountStudents() == 23);
        }
    }

    class University
    {
        private string rectorName;
        private string name;
        private Audience audience;

        public string getRectorName()
        {
            return rectorName;
        }
        public string getname()
        {
            return name;
        }

        public Audience getAudience()
        {
            return audience;
        }

        public void deduct(Group group, int amount)
        {
            if (rectorName == null || rectorName == "")
            {
                Console.WriteLine("error: rector needed");
                return;
            }
            if (group == null)
            {
                Console.WriteLine("error: group is invalid");
                return;
            }
            if (amount < 0)
            {
                Console.WriteLine("error: amount < 0");
                return;
            }
            if (group.getAmountStudents() < amount)
            {
                Console.WriteLine("error: amount > amount students");
                return;
            }
            group.updateAmountStudents(group.getAmountStudents() - amount);
        }

        public void enroll(Group group, int amount)
        {
            if (rectorName == null || rectorName == "")
            {
                Console.WriteLine("error: rector needed");
                return;
            }
            if (group == null)
            {
                Console.WriteLine("error: group is invalid");
                return;
            }
            if (amount < 0)
            {
                Console.WriteLine("error: amount < 0");
                return;
            }
            group.updateAmountStudents(group.getAmountStudents() + amount);
        }

        public void setName(string name)
        {
            if (name == null || name == "")
            {
                Console.WriteLine("error: name is incorrect");
                return;
            }
            this.name = name;
        }

        public void setRectorName(string rectorName)
        {
            if (rectorName == null || rectorName == "")
            {
                Console.WriteLine("error: rector name is incorrect");
                return;
            }
            this.rectorName = rectorName;
        }
    }

    class Department
    {
        private string name;
        private string headDepartmentName;
        private string facultyName;

        public string getName()
        {
            return name;
        }
        public string getHeadDepartmentName()
        {
            return headDepartmentName;
        }
        public string getFacultyName()
        {
            return facultyName;
        }

        public void setName(string name)
        {
            if (name == null || name == "")
            {
                Console.WriteLine("error: name is incorrect");
                return;
            }
            this.name = name;
        }

        public void setHeadDepartmentName(string headDepartmentName)
        {
            if (headDepartmentName == null || headDepartmentName == "")
            {
                Console.WriteLine("error: head department name is incorrect");
                return;
            }
            this.headDepartmentName = headDepartmentName;
        }

        public void setFacultyName(string facultyName)
        {
            if (facultyName == null || facultyName == "")
            {
                Console.WriteLine("error: faculty name is incorrect");
                return;
            }
            this.facultyName = facultyName;
        }

        public Audience getNewAudience()
        {
            if (headDepartmentName == null || name == "")
            {
                Console.WriteLine("error: head department needed");
            }
            return new Audience();
        }

        public void holdSeminar(Group group)
        {
            if (group == null || headDepartmentName == null || headDepartmentName == "")
            {
                Console.WriteLine("error: data is incorrect");
                return;
            }
            Console.WriteLine("Seminar was hosted by department head ({0}) for group ({1})", headDepartmentName, group.getName());
        }
    }

    class Exam
    {
        private List<bool> answers = new List<bool>() {true, true, false, true};
        private bool isFinished = true;
        private string teacherName;
        public List<bool> getAnswers()
        {
            return answers;
        }

        public bool getIsFinished()
        {
            return isFinished;
        }

        public string getTeacherName()
        {
            return teacherName;
        }

        public void updateAnswers(List<bool> newAnswers)
        {
            if (newAnswers == null || newAnswers.Count == 0)
            {
                Console.WriteLine("error: new answers is incorrect");
            }
            answers = newAnswers;
        }

        public void setTeacherName(string name)
        {
            if (name == null || name == "")
            {
                Console.WriteLine("error: teacher name is incorrect");
                return;
            }
            this.teacherName = name;
        }

        public void startExam()
        {
            if (teacherName == null)
            {
                Console.WriteLine("error: no teacher to start the exam");
            }
            isFinished = false;
        }

        public void finishExam()
        {
            isFinished = true;
        }

        public int turnAnswers(List<bool> answers)
        {
            int countAnswer = this.answers.Count();
            if (answers.Count() != countAnswer)
            {
                Console.WriteLine("error: the number of responses does not match");
                return -1;
            }

            int numberCorrectAnswers = 0;
            for (int i = 0; i < countAnswer; i++)
            {
                if (this.answers[i] == answers[i])
                {
                    numberCorrectAnswers++;
                }
            }
            if (numberCorrectAnswers > 0 && numberCorrectAnswers != countAnswer)
            {
                return 8;
            }
            else if (numberCorrectAnswers == countAnswer)
            {
                return 10;
            }
            else
            {
                return 4;
            }
        }
    }

    class Audience
    {
        private string name;
        private Group group;
        private string teacherName;

        public string getName()
        {
            return name;
        }

        public Group getGroup()
        {
            return group;
        }

        public string getTeacherName()
        {
            return teacherName;
        }

        public void setName(string name)
        {
            if (name == null || name == "")
            {
                Console.WriteLine("error: name is incorrect");
                return;
            }
            this.name = name;
        }

        public void setTeacherName(string name)
        {
            if (name == null || name == "")
            {
                Console.WriteLine("error: teacher name is incorrect");
                return;
            }
            this.teacherName = name;
        }

        public void changeGroup(Group group)
        {
            if (group.getAmountStudents() == 0 || group.getName() == "" || group.getName() == null)
            {
                Console.WriteLine("error: Group is incorrect");
                return;
            }
            this.group = group;
        }

        public void giveLecture()
        {
            if(group == null 
                || name == null || name == "" 
                || teacherName == null || teacherName == "")
            {
                Console.WriteLine("error: data is incorrect");
                return;
            }
            Console.WriteLine("The lecture was held by the teacher ({0}) for the group ({1})", teacherName, group.getName());
        }
    }

    class Group
    {
        private string name;
        private int amountStudents = 0;
        private int studyYear = 0;

        public string getName()
        {
            return name;
        }

        public int getAmountStudents()
        {
            return amountStudents;
        }

        public int getStudyYear()
        {
            return studyYear;
        }

        public void setName(string name)
        {
            if (name == null || name == "")
            {
                Console.WriteLine("error: name is incorrect");
                return;
            }
            this.name = name;
        }

        public void updateAmountStudents(int amount)
        {
            if (amount < 1)
            {
                Console.WriteLine("error: amount < 0");
                return;
            }
            amountStudents = amount;
        }

        public void updateStudyYear(int studyYear)
        {
            if (studyYear < 1 || studyYear > 4)
            {
                Console.WriteLine("error: study year < 0 or study year > 4");
                return;
            }
            this.studyYear = studyYear;
        }
    }
}