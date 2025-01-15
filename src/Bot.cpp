#include "Server.hpp"
#include <iostream>
#include <string>
#include <unistd.h>

void tellLittleRedRidingHood(int fd) {
	std::string message = R"(
	Un jour, une petite fille en capuchon rouge part porter un panier
	de provisions à sa grand-mère malade. En chemin, elle rencontre un
	loup rusé qui lui propose un défi : arrivera-t-elle chez sa
	grand-mère plus vite que lui ? La petite fille s'arrête pour cueillir
	des fleurs, et le loup arrive le premier. Il se déguise en grand-mère,
	mais grâce à l'aide d'un chasseur courageux, le loup est vaincu, et
	tout finit bien.
	)";
	write(fd, message.c_str(), message.length());
}

void tellThreeLittlePigs(int fd) {
	std::string message = R"(
	Trois petits cochons décident de construire chacun une maison pour se
	protéger du grand méchant loup. Le premier construit en paille, le
	second en bois, et le troisième en briques. Le loup souffle sur les
	deux premières maisons et les détruit, mais il ne peut rien contre la
	maison de briques. Les cochons apprennent l'importance de travailler
	dur et de bien se préparer.
	)";
	write(fd, message.c_str(), message.length());
}

void tellUglyDuckling(int fd) {
	std::string message = R"(
	Un caneton au plumage terne est moqué par les autres animaux. Il se
	sent seul et triste jusqu'à ce qu'il découvre, en grandissant, qu'il
	est en réalité un magnifique cygne. Cette histoire enseigne que la
	beauté intérieure et la patience permettent d'affronter les défis
	de la vie.
	)";
	write(fd, message.c_str(), message.length());
}

void tellLittleMermaid(int fd) {
	std::string message = R"(
	Ariel, une jeune sirène, rêve de découvrir le monde des humains. Elle
	sauve un prince d'un naufrage et tombe amoureuse. Elle échange sa voix
	contre des jambes auprès d'une sorcière des mers. Malgré de nombreux
	obstacles, Ariel prouve que le courage et l'amour sincère sont les
	plus grandes forces.
	)";
	write(fd, message.c_str(), message.length());
}

void tellSnowWhite(int fd) {
	std::string message = R"(
	Une jeune princesse, Blanche-Neige, est jalousée par sa belle-mère,
	la méchante reine, à cause de sa beauté. Chassée de chez elle, elle
	trouve refuge chez sept nains adorables. Mais la reine, déguisée, lui
	offre une pomme empoisonnée. Heureusement, un prince la réveille avec
	un baiser d'amour sincère, et ils vivent heureux pour toujours.
	)";
	write(fd, message.c_str(), message.length());
}

void tellHareAndTortoise(int fd) {
	std::string message = R"(
	Dans cette fable de La Fontaine, un lièvre arrogant défie une tortue
	lente à une course. Sûr de gagner, le lièvre fait une sieste en
	chemin, tandis que la tortue avance lentement mais sûrement. La tortue
	finit par remporter la course, montrant que la persévérance est plus
	importante que la vitesse.
	)";
	write(fd, message.c_str(), message.length());
}

void tellHanselAndGretel(int fd) {
	std::string message = R"(
	Un frère et une sœur, Hansel et Gretel, se perdent dans la forêt et
	découvrent une maison en pain d'épices. Mais la maison appartient à
	une sorcière qui veut les dévorer. Grâce à leur courage et à leur
	intelligence, ils réussissent à s'échapper et à retrouver leur chemin
	vers leur maison, plus unis que jamais.
	)";
	write(fd, message.c_str(), message.length());
}

void tellPussInBoots(int fd) {
	std::string message = R"(
	Un jeune homme hérite d'un chat rusé et intelligent. Ce chat, avec ses
	bottes et son esprit vif, aide son maître à devenir riche et respecté.
	Grâce à des stratagèmes habiles, il impressionne un roi, conquiert un
	château et fait en sorte que son maître épouse une princesse.
	)";
	write(fd, message.c_str(), message.length());
}

void displayWelcomeMessage(int fd) {
	std::string welcome_message = R"(
	******************************************************
	*                                                    *
	*       🌟 Bienvenue sur le Bot d'Histoires 🌟       *
	*                                                    *
	*    Ici, vous pourrez écouter de magnifiques        *
	*    histoires pour petits et grands !               *
	*                                                    *
	******************************************************

	📚 Sélectionnez une histoire parmi les options ci-dessous :

	[0] Le Petit Chaperon Rouge
	[1] Les Trois Petits Cochons
	[2] Le Vilain Petit Canard
	[3] La Petite Sirène
	[4] Blanche-Neige
	[5] Le Lièvre et la Tortue
	[6] Hansel et Gretel
	[7] Le Chat Botté

	******************************************************

	🔒 **Répondez en message privé pour choisir une histoire !** 🔒
	)";
	write(fd, welcome_message.c_str(), welcome_message.length());
}

void botResponse(const std::string& msg, int fd) {
	switch (std::stoi(msg)) {
		case 0: tellLittleRedRidingHood(fd); break;
		case 1: tellThreeLittlePigs(fd); break;
		case 2: tellUglyDuckling(fd); break;
		case 3: tellLittleMermaid(fd); break;
		case 4: tellSnowWhite(fd); break;
		case 5: tellHareAndTortoise(fd); break;
		case 6: tellHanselAndGretel(fd); break;
		case 7: tellPussInBoots(fd); break;
		default:
			displayWelcomeMessage(fd);
	}
}
