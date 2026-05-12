
import nltk
from nltk.chat.util import Chat, reflections

pairs = [

    [
        r"my name is (.*)",
        ["Hello %1, How are you?"]
    ],

    [
        r"(hi|hello|hey|hola)",
        ["Hello! My name is Heisenberg."]
    ],

    [
        r"what is your name ?",
        ["I am a bot created by Heisenberg. You can call me Crazy!"]
    ],

    [
        r"how are you ?",
        ["I'm doing good. How about you?"]
    ],

    [
        r"sorry (.*)",
        ["It's alright.", "It's OK, never mind."]
    ],

    [
        r"i am fine",
        ["Great to hear that! How can I help you?"]
    ],

    [
        r"i (.*) good",
        ["Nice to hear that.", "How can I help you? :)"]
    ],

    [
        r".*age.*",
        ["I'm a computer program dude. Seriously you are asking me this?"]
    ],

    [
        r"what (.*) want ?",
        ["Make me an offer I can't refuse."]
    ],

    [
        r".*created.*",
        ["Raghav created me using Python's NLTK library.", "Top secret ;)"]
    ],

    [
        r".*(location|city).*",
        ["Indore, Madhya Pradesh."]
    ],

    [
        r"how is weather in (.*)",
        ["Weather in %1 is awesome like always.",
         "Too hot man here in %1.",
         "Too cold man here in %1.",
         "Never even heard about %1."]
    ],

    [
        r"i work in (.*)",
        ["%1 is an amazing company, I have heard about it. But they are in huge loss these days."]
    ],

    [
        r".*raining in (.*)",
        ["No rain since last week here in %1.",
         "Damn it's raining too much here in %1."]
    ],

    [
        r"how (.*) health(.*)",
        ["I'm a computer program, so I'm always healthy."]
    ],

    [
        r".*(sports|game).*",
        ["I'm a very big fan of Football."]
    ],

    [
        r"who (.*) sportsperson ?",
        ["Messi", "Ronaldo", "Rooney"]
    ],

    [
        r"who (.*) (moviestar|actor)",
        ["Brad Pitt."]
    ],

    [
        r"i am looking for online guides and courses to learn data science, can you suggest ?",
        ["Crazy_Tech has many great articles with step-by-step explanation along with code, you can explore."]
    ],

    [
        r"quit",
        ["Thank you for using our intelligence services."]
    ],

    [
        r"(.*)",
        ["Sorry, I didn't understand that.",
         "Can you say that again?",
         "Please type something else."]
    ]
]


def chat():
    print("Hey there! I am Heisenberg at your service")
    chatbot = Chat(pairs, reflections)
    chatbot.converse()


if __name__ == "__main__":
    chat()

