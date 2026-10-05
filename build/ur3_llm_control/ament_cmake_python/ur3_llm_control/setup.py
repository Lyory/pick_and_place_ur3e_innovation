from setuptools import find_packages
from setuptools import setup

setup(
    name='ur3_llm_control',
    version='0.1.0',
    packages=find_packages(
        include=('ur3_llm_control', 'ur3_llm_control.*')),
)
