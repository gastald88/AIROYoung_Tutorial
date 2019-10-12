import AIROYoungTutorial as AYT

#print an employee
AYT.Employee.__str__ = lambda e: '{} ({} hours per day)'.format(e.name, e.hours_per_day)

#print a customer
AYT.Customer.__str__ = lambda c: 'id:{}, arrival time:{}. Desired meal:{}'.format(c.id, c.arrival_time.timeOfDay(), c.desired_meal)

#print a restaurant
AYT.Restaurant.__str__ = lambda r: 'Restaurant:{!r}'.format(r.name)