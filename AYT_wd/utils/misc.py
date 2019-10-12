import datetime as dt
import ConfigParser as cp

#converts a string representing a date of format 'YYYY-M-D' to a datetime object
def stringToDate(date_str):
	return dt.datetime.strptime(date_str, '%Y-%m-%d').date()

#given an xml tree and a key it finds the corresponding text
def getXMLelem(xml_in, key):
    q = xml_in.find("ingredient[@name={!r}]".format(key))
    if q is None:
        raise Exception('key {!r} not found'.format(key))
    else:
        return q.text

#converts a string representing a time of format 'HH:MM' to a datetime object
def stringToTime(time_str):
	return dt.datetime.strptime(time_str, '%H:%M')