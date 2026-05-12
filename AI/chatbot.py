# Install NLTK before running
# pip install nltk

import nltk # natural language toolkit
from nltk.chat.util import Chat, reflections
# Chat = prebuilt chatbot class provided by nltk
# reflections = dictionary used to to automatically swap words from question to answer.

# Define question-answer pairs
pairs = [

    [
        r"my name is (.*)",
        ["Hello %1, How are you today ?"]
    ],

    [
        r"hi|hey|hello",
        ["Hello", "Hey there"]
    ],

    [
        r"what is your name ?",
        ["I am a chatbot created using Python NLTK library."]
    ],

    [
        r"how are you ?",
        ["I am doing good. How about you ?"]
    ],

    [
        r"sorry (.*)",
        ["Its alright", "No problem"]
    ],

    [
        r"i am fine",
        ["Great to hear that!"]
    ],

    [
        r"what can you do ?",
        ["I can chat with you and answer simple questions."]
    ],

    [
        r"quit",
        ["Bye! Have a nice day."]
    ]
]

# Create chatbot object
chatbot = Chat(pairs, reflections)

# Start chatbot
print("Hello! I am your chatbot.")
print("Type 'quit' to exit.\n")

chatbot.converse()