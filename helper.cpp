#include "helper.h"
#include "hashtable.h"
std::string get_file_name()
{
  bool running = true;
  std::fstream datafile;
  std::string filename;

  std::cout << "Please enter the file name below.\n";

  while (running)
  {
    filename = word_val() + ".txt";
    datafile.open(filename);
    if (datafile.fail())
    {
      std::cout << "Failed to open file, please try again.\n";
      datafile.clear();
      running = true;
    }
    else
    {
      running = false;
    }
  }
  return filename;
}

// Reuse: Add instructions on how to read in/process/save the data. Ex: Into array to access later.
void read_data(std::string filename)
{
  std::ifstream datafile;
  datafile.open(filename);

  // Process Data however applicable
  datafile.close();
	
}
void read_accounts(std::vector<Account> &accounts)
{
  std::ifstream datafile;
  datafile.open("accounts.txt");
	
  std::string user, level;

  std::string line;
  while (std::getline(datafile, line))
  {
    std::stringstream line_ss(line);
	//name, pm_number
    std::getline(line_ss, user, ',');
    std::getline(line_ss, level, ',');

    
    Account newaccount(user, stoi(level));
    accounts.push_back(newaccount);
  }
  datafile.close();
}

void update_account(std::vector<Account> &accounts)
{
  std::ofstream datafile;
  datafile.open("accounts.txt", std::ios::out);
  for (int i = 0; i < accounts.size(); i++)
  {
    datafile << accounts[i].get_username() << ", " << accounts[i].get_level() << "\n";
	  //std::cout << accounts[i].get_username() <<", " << accounts[i].get_level() << "\n";
  }
	
  datafile.close();
}

Account &chooseAccount(std::vector<Account> &accounts)
{
  std::cout << "==== List of Accounts ====\n";
  for (int i = 0; i < accounts.size(); i++)
  {

    std::cout << std::left << std::setw(2) << std::to_string(i + 1) << " - " << std::setw(20) << accounts[i].get_username();
    if ((i + 1) % 3 == 0)
    {
      std::cout << std::endl;
    }
  }
  std::cout << "\n=========================\n";
  // Chooses between 1-n and it will return the account
  return accounts[menu_val(accounts.size()) - 1];
}

// Reuse: Write instuction on how to properly format the data to write into the text file.
void save_data()
{
  std::ofstream savefile;
  std::string filename = get_file_name();
  savefile.open(filename);

  std::cout << "\nSAVING...\n";
  // Write Data into a seperate text file in appropriate formatting.
  // savefile << ;

  std::cout << "SAVED.\n";
  savefile.close();
}
