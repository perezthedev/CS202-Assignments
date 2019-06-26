//  CS 202
//  Assignment #4 - Provided Main
//  Uses and tests various functions from the contact list class

#include <iostream>
#include <string>

#include "contactList.h"

using namespace std;

int main()
{
// ----------------------------------------------------------------------
//  Display a simple header...

	string	stars, bars;
	stars.append(60,'*');
	bars.append(50,'-');

	cout << stars << endl;
	cout << "CS 202 - Assignment #4" << endl;
	cout << "Contact List Testing (base class)" << endl << endl;

// ----------------------------------------------------------------------
//  Declare some contacts.

	contactList simpson("Simpson", "Homer", "742 Evergreen Terrace", "",
			"Springfield", "OR", "80085", "chunkylover53@aol.com",
			"939-555-8707", "939-555-5246" );
	contactList squarepants("Squarepants", "SpongeBob", "124 Conch St", "Bikini Bottom",
			"Pacific Ocean", "TX", "73301", "spongebob@nickelodian.com",
			"512-555-6464", "512-555-4646" );
	contactList carlson("Carlson", "Carl");
	contactList bouvier("Bouvier", "Selma", "Spinster Apparments", "Apt #666", "Spinster City", 
			"OR", "80085", "Selma_Bouvier@SelmaBouvier.com", "636-555-1234");
	contactList krabappel("Krabappel", "Edna", "82 Evergreen Terrace", "", "Springfield", "OR",
			"80085", "teacher@elementary.edu", "939-555-8848", "939-555-7201");
	contactList neahasapeemapetilon("Nahasapeemapetilon", "Apu", "1611 W Olive Ave", "", "Burbank",
			"CA", "91506", "apu@kwikemart.com", "818-842-1210", "");
	contactList groundskeeper("Groundskeeper", "Willie", "Shack", "Springfield Elementary",
			"Springfield", "OR", "80085", "Groundskeeper.Willie@ThaRealWillie.gov");
	contactList riviera("Riviera", "Nick", "Back Alley", "Shady Street", "Springfield", "OR", "80085",
			"drNick@shiftyDoctors.com", "636-555-6425");
	contactList jetson("Jetson", "George", "Skypad Apartments", "Apt #777", "Orbit City", "NV", "10001",
				"george@SpacelySpaceSprockets.com", "535-555-0191", "535-555-1010");
	contactList munster("Munster", "Herman", "1313 Mockingbird Lane", "", "Mockingbird Heights", "CA",
				"90001", "herman@strange.com", "666-555-1234", "666-555-4321");
	contactList newContact1;
	contactList newContact2("Gumble", "Barney");

	const	int	contactCnt=5;
	contactList tempContacts[contactCnt];

// ----------------------------------------------------------------------
//  Enter data (via setters).

	newContact1.setName("Hutz", "Lionel");
	newContact1.setAddress("Phone Booth", "Main Street", "Springfield", "OR", "80085");
	newContact1.setEmail("lionel@springfield.com");
	newContact1.setPhone("939-555-5299", "");

	newContact2.setAddress("Skid Row", "Main Street", "Springfield", "OR", "80085");
	newContact2.setEmail("barnet@temp.com");
	newContact2.setPhone("939-555-9191", "");

	tempContacts[0].setName("Spuckler", "Cletus");
	tempContacts[0].setAddress("Shack #3", "Backwoods", "Springfield", "OR", "80085");

	tempContacts[1].setName("Terwilliger", "Cecil");
	tempContacts[1].setAddress("1 Highbrow Way", "Main Street", "Capital City", "OR", "58008");
	tempContacts[1].setEmail("cecil@opera.com");
	tempContacts[1].setPhone("636-555-5299", "636-555-1212");

	tempContacts[2].setName("Addams", "Gomez");
	tempContacts[2].setAddress("001 Cemetery Lane", "", "Greenbriar", "WA", "99169");
	tempContacts[2].setEmail("gomez@addams.org");
	tempContacts[2].setPhone("636-555-5299", "636-555-1212");

	tempContacts[3].setName("Fry", "Phillip");
	tempContacts[3].setAddress("Robot Arms Apartments", "Apt # 00100100", "New New York", "NY", "10007");
	tempContacts[3].setEmail("fry@planetExpress.com");
	tempContacts[3].setPhone("", "222-555-1077");

// ----------------------------------------------------------------------
//  Change name (due to marriage).

	bouvier.setName("McClure", bouvier.getFirstName() );

// ----------------------------------------------------------------------
//  Copy one of the contacts into a different object (testing getters).

	string	addr1, addr2, city, state, zip;
	string	phoneHm, phoneWrk;

	tempContacts[4].setName(simpson.getLastName(), simpson.getFirstName());
	simpson.getAddress(addr1, addr2, city, state, zip);
	tempContacts[4].setAddress(addr1, addr2, city, state, zip);
	tempContacts[4].setEmail(simpson.getEmail());
	simpson.getPhone(phoneHm, phoneWrk);
	tempContacts[4].setPhone(phoneHm, phoneWrk);

// ----------------------------------------------------------------------
//  Some error testing -> all of these should be errors...

	// bad state
	contactList lisaS1("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "RO", "80085", "lisa_simpson@yahoo.com",
			"939-555-8707", "939-555-5246" );
	contactList lisaS2("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "ORR", "80085", "lisa_simpson@yahoo.com",
			"939-555-8707", "939-555-5246" );

	// bad zip
	contactList lisaZ1("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "OR", "885", "lisa_simpson@yahoo.com",
			"939-555-8707", "939-555-5246" );
	contactList lisaZ2("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "OR", "800855", "lisa_simpson@yahoo.com",
			"939-555-8707", "939-555-5246" );
	contactList lisaZ3("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "OR", "80a85", "lisa_simpson@yahoo.com",
			"939-555-8707", "939-555-5246" );


	// bad email
	contactList lisaE1("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "OR", "80085", "@yahoo.com",
			"939-555-8707", "939-555-5246" );
	contactList lisaE2("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "OR", "80085", "lisa_simpsonyahoo.com",
			"939-555-8707", "939-555-5246" );
	contactList lisaE3("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "OR", "80085", "lisa_simpson@yahoo.c",
			"939-555-8707", "939-555-5246" );
	contactList lisaE4("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "OR", "80085", "lisa_simpson@.com",
			"939-555-8707", "939-555-5246" );
	contactList lisaE5("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "OR", "80085", "lisa_simpson@yahoocom",
			"939-555-8707", "939-555-5246" );
	contactList lisaE6("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "OR", "80085", "lisa_simpson@yahoo.zom",
			"939-555-8707", "939-555-5246" );
	contactList lisaE7("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "OR", "80085", "lisa_simp;on@yahoo.com",
			"939-555-8707", "939-555-5246" );

	// bad phone numbers
	contactList lisaP1("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "OR", "80085", "lisa_simpson@yahoo.com",
			"93-1555-8707", "939-555-5246" );
	contactList lisaP2("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "OR", "80085", "lisa_simpson@yahoo.com",
			"939-1555-8707", "939-555-5246" );
	contactList lisaP3("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "OR", "80085", "lisa_simpson@yahoo.com",
			"939-555-807", "939-555-5246" );
	contactList lisaP4("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "OR", "80085", "lisa_simpson@yahoo.com",
			"939-555-8a07", "939-555-5246" );
	contactList lisaP5("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "OR", "80085", "lisa_simpson@yahoo.com",
			"939-555-8707", "9a9-555-5246" );
	contactList lisaP6("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "OR", "80085", "lisa_simpson@yahoo.com",
			"939-555-8707", "939-55-5246" );
	contactList lisaP7("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "OR", "80085", "lisa_simpson@yahoo.com",
			"939-555-8707", "939-55535246" );
	contactList lisaP8("Simpson", "Lisa", "742 Evergreen Terrace", "",
			"Springfield", "OR", "80085", "lisa_simpson@yahoo.com",
			"939-555-8707", "9391555-5246" );

	contactList bart;
	bart.setName("Simpson", "Bart");

	// bad state
	bart.setAddress("742 Evergreen Terrace", "", "Springfield", "XT", "80085");
	bart.setAddress("742 Evergreen Terrace", "", "Springfield", "T", "80085");
	bart.setAddress("742 Evergreen Terrace", "", "Springfield", "LM", "80085");
	bart.setAddress("742 Evergreen Terrace", "", "Springfield", "VN", "80085");

	// bad email address
	bart.setEmail("bart.simpson@.com");
	bart.setEmail("bart.simpson@hotmail");
	bart.setEmail("bart.simpson@hotmailcom");
	bart.setEmail("l@.com");
	bart.setEmail("@hotmail.com");
	bart.setEmail("bart.simpsonhotmail.com");

	// bad phone numbers
	bart.setPhone("9391555-8707", "939-555-5246");
	bart.setPhone("939-5a5-8707", "939-555-5246");
	bart.setPhone("939-555-877", "939-555-5246");
	bart.setPhone("939-555-8707", "9391555-5246");
	bart.setPhone("939-555-8707", "939-55515246");
	bart.setPhone("939-555-8707", "939-555--246");

// ----------------------------------------------------------------------
//  Show contacts for all

	cout << endl << stars << endl;
	cout << "Contact List:" << endl << endl;

	simpson.displayContact();
	squarepants.displayContact();
	carlson.displayContact();;
	bouvier.displayContact();
	krabappel.displayContact();
	neahasapeemapetilon.displayContact();
	groundskeeper.displayContact();
	riviera.displayContact();
	jetson.displayContact();
	munster.displayContact();

	newContact1.displayContact();
	newContact2.displayContact();

	for (int i=0; i < contactCnt; i++)
		tempContacts[i].displayContact();

// ----------------------------------------------------------------------
//  All done, terminate program.

	cout << endl;
	return 0;
}
