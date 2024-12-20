document.getElementById('registerForm').addEventListener('submit', async function (e) {
    e.preventDefault();
  
    const name = document.getElementById('name').value;
    const email = document.getElementById('email').value;
    const password = document.getElementById('password').value;
  
    try {
      const response = await fetch('https://jsonplaceholder.typicode.com/posts', {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify({ name, email, password }),
      });
  
      const data = await response.json();
      document.getElementById('registerMessage').textContent = 'Registration Successful!';
      console.log('Response:', data);
    } catch (error) {
      document.getElementById('registerMessage').textContent = 'Registration Failed.';
      console.error(error);
    }
  });
  async function fetchEmployees() {
    try {
      const response = await fetch('https://jsonplaceholder.typicode.com/users');
      const employees = await response.json();
  
      const employeeList = document.getElementById('employeeList');
      employees.forEach(employee => {
        const employeeCard = document.createElement('div');
        employeeCard.className = 'card';
        employeeCard.innerHTML = `
          <h3>${employee.name}</h3>
          <p>Email: ${employee.email}</p>
          <p>Phone: ${employee.phone}</p>
          <p>Website: ${employee.website}</p>
        `;
        employeeList.appendChild(employeeCard);
      });
    } catch (error) {
      console.error('Error fetching employees:', error);
    }
  }
  
  // Fetch employees on page load
  fetchEmployees();
  
  