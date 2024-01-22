## OOP Project Description

### Part 1: Student Management System

#### Classes:

1. **Note Class:**
   - `Note` class represents a student's performance in a particular subject.
   - Private attributes: `NoteControle` (control/test score) and `NoteExamen` (exam score).
   - Public methods: `getNoteControle()`, `getNoteExamen()`.

2. **Student Class:**
   - `Etudiant` class represents a student.
   - Private attributes: `identifiant` (ID), `nom` (last name), `prenom` (first name), and a vector of `Note` objects.
   - Public methods: `getID()`, `getNom()`, `getPrenom()`, `moyenne()` (calculates the average), `getNote()`.
   
3. **Management Class:**
   - `Gestion` class manages students.
   - Private attribute: A vector of `Etudiant` objects.
   - Public methods: `saisir_etudiant()` (input student data), `creer_fichier()` (creates a file with student data), `etudiants_reussis()` (identifies and stores successful students), `Affiche()` (displays successful students).

#### Main Functionality:

1. The program allows users to input information for a specified number of students, including their names, IDs, and scores for 10 subjects.
2. It can create a text file (`etudiants.txt`) with the entered student information.
3. It identifies successful students (those with an average score of 10 or above), sorts them by average score, and stores the information in another text file (`res.txt`).
4. It can display the information of successful students.

### Part 2: Person Management System

#### Classes:

1. **Person Class:**
   - `Personne` class is an abstract base class for different types of people.
   - Protected attributes: `id` (ID), `nom` (last name), `prenom` (first name).
   - Public methods: `afficher()` (displays basic information), `get_id()`, `get_nom()`, `get_prenom()`.

2. **Note Class (used in Part 2):**
   - Same as the `Note` class in Part 1.

3. **Student Class (derived from Person):**
   - `Etudiant` class is derived from `Personne` and includes additional information about student performance.
   - Private attribute: Vector of `Note` objects.
   - Public methods: `getNote()`, `moyenne()`, `afficher()`.

4. **Professor Class (derived from Person):**
   - `Professeur` class is derived from `Personne` and includes information about the course taught.
   - Private attribute: `cours` (course).
   - Public methods: `get_cours()`, `afficher()`.

5. **Personnel Class (derived from Person):**
   - `Personnel` class is derived from `Personne` and includes information about the person's job.
   - Private attribute: `metier` (occupation).
   - Public methods: `get_metier()`, `afficher()`.

#### Main Functionality:

1. The program creates instances of different types of people (professor, personnel, student).
2. It uses polymorphism to display basic information for each person, including additional details for students (grades, course for professors, occupation for personnel).
3. Demonstrates the use of abstract base class and polymorphism.

### Usage:

- The main function in each part demonstrates the functionality of the respective classes and their interactions. 
- Users can modify and extend the code according to specific requirements or use cases.
- The code can be compiled and executed to test the implemented functionality.
